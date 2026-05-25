using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data.SqlClient;
using System.IO;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace ppppppppppppppppppp
{
    public partial class editinfo : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            try
            {
                string imageFolderPath = Server.MapPath("~/imageadd/");
                if (!Directory.Exists(imageFolderPath))
                {
                    Directory.CreateDirectory(imageFolderPath);
                }

                string connectionString = ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString;

                using (SqlConnection sqlcon = new SqlConnection(connectionString))
                {
                    sqlcon.Open();

                    string query = "UPDATE Projects SET ProjectName = @ProjectName, ProjectDescription = @Description, RequirementsFile = @FilePath, ProjectImage = @ImagePath WHERE ProjectID = @ProjectID";

                    // Variables for file paths
                    string imageRelativePath = null;
                    string fileRelativePath = null;

                    if (FileUpload1.HasFile)
                    {
                        string fileName = Path.GetFileName(FileUpload1.FileName);
                        string filePath = Path.Combine(imageFolderPath, fileName);
                        FileUpload1.SaveAs(filePath);
                        fileRelativePath = "imageadd/" + fileName;
                    }

                    if (FileUpload2.HasFile)
                    {
                        string imageName = Path.GetFileName(FileUpload2.FileName);
                        string imagePath = Path.Combine(imageFolderPath, imageName);
                        FileUpload2.SaveAs(imagePath);
                        imageRelativePath = "imageadd/" + imageName;
                    }

                    using (SqlCommand mycommand = new SqlCommand(query, sqlcon))
                    {
                        mycommand.Parameters.AddWithValue("@ProjectID", TextBox1.Text);
                        mycommand.Parameters.AddWithValue("@ProjectName", TextBox2.Text);
                        mycommand.Parameters.AddWithValue("@Description", TextBox3.Text);

                        if (!string.IsNullOrEmpty(imageRelativePath))
                        {
                            mycommand.Parameters.AddWithValue("@ImagePath", imageRelativePath);
                        }
                        else
                        {
                            mycommand.Parameters.AddWithValue("@ImagePath", DBNull.Value);
                        }

                        if (!string.IsNullOrEmpty(fileRelativePath))
                        {
                            mycommand.Parameters.AddWithValue("@FilePath", fileRelativePath);
                        }
                        else
                        {
                            mycommand.Parameters.AddWithValue("@FilePath", DBNull.Value);
                        }

                        int rowsAffected = mycommand.ExecuteNonQuery();
                        Response.Write($"<script>alert('{rowsAffected} row(s) updated successfully.');</script>");
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
