using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace ppppppppppppppppppp
{
    public partial class manage : System.Web.UI.Page
    {
        private string connectionString = ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString;

        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                BindGridView(); // تأكد من ربط البيانات بالـ GridView عند تحميل الصفحة
            }
        }
        private void BindGridView()
        {
            // طريقة جلب البيانات وعرضها في GridView1 (مثال)
            string query = "SELECT RequestID, EmployeeID, Skill1, Skill2, Skill3, TotalPoints, ProjectID, [the Role] FROM Requests ORDER BY TotalPoints DESC";
            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                SqlCommand command = new SqlCommand(query, connection);
                try
                {
                    connection.Open();
                    GridView1.DataSource = command.ExecuteReader();
                    GridView1.DataBind();

                }
                catch (Exception ex)
                {
                    Response.Write("Error: " + ex.Message);
                }
            }
        }
        protected void Button1_Click(object sender, EventArgs e)
        {

        }

        protected void GridView1_RowCommand(object sender, GridViewCommandEventArgs e)
        {
            if (e.CommandName == "Accept" || e.CommandName == "Reject")
            {
                int rowIndex = Convert.ToInt32(e.CommandArgument);
                GridViewRow row = GridView1.Rows[rowIndex];

                string requestID = row.Cells[0].Text;
                string employeeID = row.Cells[1].Text; // تعديل الفهرس حسب مكان EmployeeID
                int totalPoints = Convert.ToInt32(row.Cells[5].Text); // العمود السادس: TotalPoints
                string projectID = row.Cells[6].Text;      // العمود السابع: ProjectID
                string theRole = row.Cells[7].Text;

                // تحقق من الشروط: TotalPoints أكبر من رقم معين (مثلاً 50) و Role هو "employee".
                if ((totalPoints > 200 && theRole.Equals("manager", StringComparison.OrdinalIgnoreCase)) ||
     (totalPoints > 100 && theRole.Equals("employee", StringComparison.OrdinalIgnoreCase)))
                {
                    string theStatus = (e.CommandName == "Accept") ? "Accepted" : "Rejected";

                    // كتابة استعلام SQL لإضافة البيانات إلى جدول TemporaryRequests.
                    string insertQuery = "INSERT INTO TemporaryRequests (RequestID, EmployeeID, ProjectID, [the Role], [the status]) VALUES (@RequestID, @EmployeeID, @ProjectID, @TheRole, @TheStatus)";

                    using (SqlConnection connection = new SqlConnection(connectionString))
                    {
                        SqlCommand command = new SqlCommand(insertQuery, connection);
                        command.Parameters.AddWithValue("@RequestID", requestID);
                        command.Parameters.AddWithValue("@EmployeeID", employeeID);
                        command.Parameters.AddWithValue("@ProjectID", projectID);
                        command.Parameters.AddWithValue("@TheRole", theRole);
                        command.Parameters.AddWithValue("@TheStatus", theStatus);

                        try
                        {
                            connection.Open();
                            int rowsAffected = command.ExecuteNonQuery();
                            if (rowsAffected > 0)
                            {
                                // عرض رسالة نجاح وتحديث GridView إذا لزم الأمر.
                                ScriptManager.RegisterStartupScript(this, GetType(), "alert", "alert('the mission is done!');", true);
                                GridView2.DataBind();
                            }
                            else
                            {
                                Response.Write($"فشل نقل الطلب رقم {requestID}.");
                            }
                        }
                        catch (Exception ex)
                        {
                            // معالجة الخطأ هنا
                            Response.Write("Error: " + ex.Message);
                        }
                    }
                }
                else
                {
                    // تعطيل الزر إذا لم يتحقق الشرط
                    Button acceptButton = row.FindControl("AcceptButton") as Button;
                    if (acceptButton != null)
                    {
                        acceptButton.Enabled = false;
                    }
                    ScriptManager.RegisterStartupScript(this, GetType(), "alert", "alert('Data cannot be transferred. Check the points and the roles.');", true);
                }
            }
        }

        protected void GridView2_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        protected void Button2_Click(object sender, EventArgs e)
        {
            string selectQuery = "SELECT ProjectID, [the Role], EmployeeID, [the status] FROM TemporaryRequests WHERE [the status] = 'Accepted'";
            string getRolesQuery = "SELECT RoleName, RoleID FROM Roles";

            Dictionary<string, int> roles = new Dictionary<string, int>();

            // المرحلة الأولى: تحميل الأدوار إلى قاموس
            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();

                using (SqlCommand getRolesCommand = new SqlCommand(getRolesQuery, connection))
                using (SqlDataAdapter adapter = new SqlDataAdapter(getRolesCommand))
                {
                    DataTable rolesTable = new DataTable();
                    adapter.Fill(rolesTable);

                    foreach (DataRow row in rolesTable.Rows)
                    {
                        roles.Add(row["RoleName"].ToString().ToLower(), Convert.ToInt32(row["RoleID"]));
                    }
                }
            }

            // المرحلة الثانية: معالجة الطلبات باستخدام البيانات المخزنة
            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();
                SqlTransaction transaction = connection.BeginTransaction();

                try
                {
                    using (SqlCommand selectCommand = new SqlCommand(selectQuery, connection, transaction))
                    using (SqlDataAdapter adapter = new SqlDataAdapter(selectCommand))
                    {
                        DataTable requestsTable = new DataTable();
                        adapter.Fill(requestsTable);

                        foreach (DataRow row in requestsTable.Rows)
                        {
                            string projectID = row["ProjectID"].ToString();
                            string role = row["the Role"].ToString().ToLower();
                            string employeeID = row["EmployeeID"].ToString();

                            if (roles.ContainsKey(role))
                            {
                                int roleId = roles[role];

                                if (role == "manager")
                                {
                                    string addManagerToEmployeeQuery = @"
                            UPDATE Employees
                            SET RoleID = @RoleID, ProjectID = @ProjectID
                            WHERE EmployeeID = @EmployeeID";

                                    string updateProjectQuery = @"
                            UPDATE Projects
                            SET ProjectManagerID = @EmployeeID
                            WHERE ProjectID = @ProjectID";

                                    try
                                    {
                                        using (SqlCommand updateEmployeeCmd = new SqlCommand(addManagerToEmployeeQuery, connection, transaction))
                                        {
                                            updateEmployeeCmd.Parameters.AddWithValue("@RoleID", roleId);
                                            updateEmployeeCmd.Parameters.AddWithValue("@ProjectID", projectID);
                                            updateEmployeeCmd.Parameters.AddWithValue("@EmployeeID", employeeID);
                                            updateEmployeeCmd.ExecuteNonQuery();
                                        }

                                        using (SqlCommand updateProjectCmd = new SqlCommand(updateProjectQuery, connection, transaction))
                                        {
                                            updateProjectCmd.Parameters.AddWithValue("@ProjectID", projectID);
                                            updateProjectCmd.Parameters.AddWithValue("@EmployeeID", employeeID);
                                            updateProjectCmd.ExecuteNonQuery();
                                        }
                                    }
                                    catch (Exception ex)
                                    {
                                        Console.WriteLine("Error: " + ex.Message);
                                    }
                                }
                                else if (role == "employee")
                                {
                                    string addEmployeeToProjectQuery = @"
                            UPDATE Employees
                            SET ProjectID = @ProjectID, RoleID = @RoleID
                            WHERE EmployeeID = @EmployeeID";

                                    using (SqlCommand command = new SqlCommand(addEmployeeToProjectQuery, connection, transaction))
                                    {
                                        command.Parameters.AddWithValue("@RoleID", roleId);
                                        command.Parameters.AddWithValue("@ProjectID", projectID);
                                        command.Parameters.AddWithValue("@EmployeeID", employeeID);
                                        command.ExecuteNonQuery();
                                    }
                                }
                            }
                            else
                            {
                                transaction.Rollback();
                                Response.Write("Role not found for: " + role);
                                return;
                            }
                        }
                    }

                    transaction.Commit();
                    ScriptManager.RegisterStartupScript(this, GetType(), "alert", "alert('تم تنفيذ العمليات بنجاح.');", true);
                    string deleteQuery = "DELETE FROM TemporaryRequests";
                    using (SqlCommand deleteCommand = new SqlCommand(deleteQuery, connection, transaction))
                    {
                        deleteCommand.ExecuteNonQuery();
                    }

                    // تحديث GridView2 لعكس التغييرات (جعله فارغًا)
                    GridView2.DataSource = null;
                    GridView2.DataBind();
                }
                catch (Exception ex)
                {
                    transaction.Rollback();
                    Response.Write("Error: " + ex.Message);
                }
            }
        }

        protected void SqlDataSource1_Selecting(object sender, SqlDataSourceSelectingEventArgs e)
        {

        }
    }
}