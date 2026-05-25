using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace ppppppppppppppppppp
{
    public partial class addrequest : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void SubmitButton_Click(object sender, EventArgs e)
        {
            if (Page.IsValid)
            {
                string employeeId = EmployeeID.Text.Trim();
                string projectId = ProjectID.Text.Trim();
                string role = EmployeeType.SelectedValue; // استلام قيمة الدور من EmployeeType

                // محاولة تحويل القيم المختارة إلى أعداد صحيحة
                if (int.TryParse(Category1.SelectedValue, out int skill1) &&
                    int.TryParse(Category2.SelectedValue, out int skill2) &&
                    int.TryParse(Category3.SelectedValue, out int skill3))
                {
                    // حساب المجموع
                    int totalPoints = skill1 + skill2 + skill3;

                    // استبدل "YourConnectionString" بسلسلة الاتصال الخاصة بك
                    string connectionString = ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString;

                    using (SqlConnection conn = new SqlConnection(connectionString))
                    {
                        // تضمين عمود Role في استعلام الإدراج
                        string query = "INSERT INTO Requests (EmployeeID, Skill1, Skill2, Skill3, ProjectID, TotalPoints, [the Role]) VALUES (@EmployeeID, @Skill1, @Skill2, @Skill3, @ProjectID, @TotalPoints, @Role)";

                        using (SqlCommand cmd = new SqlCommand(query, conn))
                        {
                            cmd.Parameters.AddWithValue("@EmployeeID", employeeId);
                            cmd.Parameters.AddWithValue("@Skill1", skill1);
                            cmd.Parameters.AddWithValue("@Skill2", skill2);
                            cmd.Parameters.AddWithValue("@Skill3", skill3);
                            cmd.Parameters.AddWithValue("@ProjectID", projectId);
                            cmd.Parameters.AddWithValue("@TotalPoints", totalPoints);
                            cmd.Parameters.AddWithValue("@Role", role); // استخدام قيمة الدور المستلمة

                            try
                            {
                                conn.Open();
                                cmd.ExecuteNonQuery();
                                // عرض رسالة نجاح
                                ScriptManager.RegisterStartupScript(this, GetType(), "alert", "alert('the mission is done!');", true);
                                // إعادة تعيين الحقول
                                EmployeeID.Text = "";
                                Category1.SelectedIndex = 0;
                                Category2.SelectedIndex = 0;
                                Category3.SelectedIndex = 0;
                                ProjectID.Text = "";
                                EmployeeType.SelectedIndex = 0; // إعادة تعيين قيمة نوع الموظف
                            }
                            catch (Exception ex)
                            {
                                // عرض رسالة خطأ
                                ScriptManager.RegisterStartupScript(this, GetType(), "alert", $"alert('حدث خطأ: {ex.Message}');", true);
                            }
                        }
                    }
                }
                else
                {
                    // عرض رسالة خطأ إذا كانت قيم الفئات غير صالحة
                    ScriptManager.RegisterStartupScript(this, GetType(), "alert", "alert('الرجاء اختيار قيم صحيحة للفئات.');", true);
                }
            }
        }

        protected void EmployeeType_SelectedIndexChanged(object sender, EventArgs e)
        {
        
        }
    }
}
