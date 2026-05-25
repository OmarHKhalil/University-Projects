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
    public partial class deletinfo : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            try
            {
                string connectionString = ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString;

                using (SqlConnection sqlcon = new SqlConnection(connectionString))
                {
                    sqlcon.Open();

                    string query = "DELETE FROM Projects WHERE ProjectID = @ProjectID";

                    using (SqlCommand mycommand = new SqlCommand(query, sqlcon))
                    {
                        mycommand.Parameters.AddWithValue("@ProjectID", TextBox1.Text);

                        int rowsAffected = mycommand.ExecuteNonQuery();
                        Response.Write($"<script>alert('{rowsAffected} row(s) deleted successfully.');</script>");
                    }
                }
            }
            catch (Exception ex)
            {
                Response.Write($"<script>alert('Error: {ex.Message}');</script>");
            }
        }
    }
}