using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace ppppppppppppppppppp
{
    public partial class log_in : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (HttpContext.Current.User.Identity.IsAuthenticated)
            {
                // إذا كان المستخدم مسجلاً بالفعل، يعاد توجيهه إلى الصفحة الرئيسية
                Response.Redirect("home.aspx");
            }
        }

        protected void Unnamed2_TextChanged(object sender, EventArgs e)
        {

        }

        protected void Button1_Click(object sender, EventArgs e)
        {

        }

        protected void btnLogin_Click(object sender, EventArgs e)
        {
            string username = txtUsername.Text;
            string password = txtPassword.Text;

            string connectionString = ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString;

            using (SqlConnection conn = new SqlConnection(connectionString))
            {
                conn.Open();

                // التحقق من وجود المستخدم وجلب RoleID و DepartmentID
                string checkUserQuery = "SELECT EmployeeID, RoleID, DepartmentID FROM Employees WHERE LOWER(uasername) = LOWER(@Username) AND password = @Password";
                using (SqlCommand checkUserCmd = new SqlCommand(checkUserQuery, conn))
                {
                    checkUserCmd.Parameters.AddWithValue("@Username", username);
                    checkUserCmd.Parameters.AddWithValue("@Password", password);

                    SqlDataReader reader = checkUserCmd.ExecuteReader();

                    if (reader.Read())
                    {
                        int employeeId = Convert.ToInt32(reader["EmployeeID"]);
                        int roleId = Convert.ToInt32(reader["RoleID"]);
                        int departmentId = Convert.ToInt32(reader["DepartmentID"]);

                        // يجب إغلاق القارئ هنا قبل تنفيذ أمر آخر على نفس الاتصال
                        reader.Close();

                        // إضافة سجل تسجيل الدخول إلى جدول Logs
                        string insertLogQuery = "INSERT INTO Logs (UserID, Action, Timestamp, password) VALUES (@UserID, @Action, @Timestamp, @Password)";
                        using (SqlCommand insertLogCmd = new SqlCommand(insertLogQuery, conn))
                        {
                            insertLogCmd.Parameters.AddWithValue("@UserID", employeeId);
                            insertLogCmd.Parameters.AddWithValue("@Action", "Login Attempt");
                            insertLogCmd.Parameters.AddWithValue("@Timestamp", DateTime.Now);
                            insertLogCmd.Parameters.AddWithValue("@Password", password);

                            insertLogCmd.ExecuteNonQuery();
                        }
                        Session["IsLoggedIn"] = true;

                        // تحديد صفحة التوجيه بناءً على RoleID و DepartmentID
                        if (roleId == 1 && departmentId == 2)
                        {
                            Response.Redirect("dbproject1.aspx"); 
                        }
                        else if (roleId == 2 && departmentId == 2)
                        {
                            Response.Redirect("dbproject2.aspx"); 
                        }
                        else if (roleId == 1 && departmentId == 1)
                        {
                            Response.Redirect("page_role2_dept2.aspx"); 
                        }
                        else if (roleId == 2 && departmentId == 1)
                        {
                            Response.Redirect("page_role3_dept1.aspx"); 
                        }
                        else if (roleId == 1 && departmentId == 3)
                        {
                            Response.Redirect("page_role3_dept2.aspx"); 
                        }
                        else if (roleId == 2 && departmentId == 3)
                        {
                            Response.Redirect("page_role4_dept1.aspx"); 
                        }
                        else if (roleId == 1 && departmentId == 4)
                        {
                            Response.Redirect("page_role4_dept2.aspx"); 
                        }
                        else if (roleId == 2 && departmentId == 4)
                        {
                            Response.Redirect("page_role4_dept2.aspx"); 
                        }
                        
                    }
                    else
                    {
                        lblErrorMessage.Text = "Incorrect username or password!";
                    }
                   
                }
            }
        }
    }
}