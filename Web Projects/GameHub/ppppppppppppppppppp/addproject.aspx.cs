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
    public partial class addproject : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void submitButton_Clic(object sender, EventArgs e)
        {
            try
            {
                bool hasError = false;

                // Clear previous validation messages
                lblProjectIDError.Text = "";
                lblProjectNameError.Text = "";
                lblDescriptionError.Text = "";
                lblFileUpload1Error.Text = "";
                lblFileUpload2Error.Text = "";

                // Validate Project ID
                if (string.IsNullOrWhiteSpace(TextBox1.Text))
                {
                    lblProjectIDError.Text = "Project ID is required.";
                    hasError = true;
                }
                else if (!System.Text.RegularExpressions.Regex.IsMatch(TextBox1.Text, @"^20\d{4}$"))
                {
                    lblProjectIDError.Text = "Project ID must be a 6-digit number starting with '20'.";
                    hasError = true;
                }
                else if (int.TryParse(TextBox1.Text, out int projectId) && projectId < 0)
                {
                    lblProjectIDError.Text = "Project ID must not be negative.";
                    hasError = true;
                }

                // Validate required fields
                if (string.IsNullOrWhiteSpace(TextBox2.Text))
                {
                    lblProjectNameError.Text = "Project Name is required.";
                    hasError = true;
                }

                if (string.IsNullOrWhiteSpace(TextBox3.Text))
                {
                    lblDescriptionError.Text = "Project Description is required.";
                    hasError = true;
                }

                // Validate file uploads
                if (!FileUpload1.HasFile)
                {
                    lblFileUpload1Error.Text = "Requirements file is required. Please upload a PDF file.";
                    hasError = true;
                }

                if (!FileUpload2.HasFile)
                {
                    lblFileUpload2Error.Text = "Project image is required. Please upload an image file (png or jpeg).";
                    hasError = true;
                }

                if (hasError)
                {
                    return;
                }

                if (!FileUpload2.HasFile)
                {
                    Response.Write("<script>alert('Project image is required. Please upload an image file (png or jpeg).');</script>");
                    return;
                }
                string imageFolderPath = Server.MapPath("~/imageadd/");
                if (!Directory.Exists(imageFolderPath))
                {
                    Directory.CreateDirectory(imageFolderPath);
                }

                string connectionString = ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString;

                using (SqlConnection sqlcon = new SqlConnection(connectionString))
                {
                    sqlcon.Open();

                    string query = "INSERT INTO Projects (ProjectID, ProjectName, ProjectDescription, RequirementsFile, ProjectImage) VALUES (@ProjectID, @ProjectName, @Description, @FilePath, @ImagePath)";

                    // Variables for file paths
                    string imageRelativePath = null;
                    string fileRelativePath = null;

                    if (FileUpload1.HasFile)
                    {
                        string fileExtension = Path.GetExtension(FileUpload1.FileName).ToLower();
                        if (fileExtension == ".pdf")
                        {
                            string fileName = Path.GetFileName(FileUpload1.FileName);
                            string filePath = Path.Combine(imageFolderPath, fileName);
                            FileUpload1.SaveAs(filePath);
                            fileRelativePath = "imageadd/" + fileName;
                        }
                        else
                        {
                            Response.Write("<script>alert('Invalid file type. Please upload a PDF file.');</script>");
                            return;
                        }
                    }

                    if (FileUpload2.HasFile)
                    {
                        string fileExtension = Path.GetExtension(FileUpload2.FileName).ToLower();

                        if (fileExtension == ".png" || fileExtension == ".jpeg")
                        {
                            string imageName = Path.GetFileName(FileUpload2.FileName);
                            string imagePath = Path.Combine(imageFolderPath, imageName);
                            FileUpload2.SaveAs(imagePath);
                            imageRelativePath = "imageadd/" + imageName;
                        }
                        else
                        {
                            Response.Write("<script>alert('Invalid image type. Please upload an image of png or jpeg type.');</script>");
                            return;
                        }
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
                        Response.Write($"<script>alert('{rowsAffected} row(s) inserted successfully.');</script>");
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