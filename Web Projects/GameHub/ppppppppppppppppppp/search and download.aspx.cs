using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace ppppppppppppppppppp
{
    public partial class search_and_download : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            GridView1.Visible = true;
        }

        protected void GridView1_RowCommand(object sender, GridViewCommandEventArgs e)
        {
            if (e.CommandName == "download")
            {
                int index = Convert.ToInt32(e.CommandArgument);
                string filename = GridView1.DataKeys[index].Values["RequirementsFile"].ToString();

                if (!string.IsNullOrEmpty(filename))
                {
                    string path = MapPath(filename);

                    if (File.Exists(path))
                    {
                        byte[] fileBytes = File.ReadAllBytes(path);

                        Response.Clear();
                        Response.ContentType = "application/octet-stream";
                        Response.AddHeader("Content-Disposition", $"attachment; filename={Path.GetFileName(filename)}");
                        Response.BinaryWrite(fileBytes);
                        Response.End();
                    }
                    else
                    {
                        // Handle file not found scenario
                        Response.Write("<script>alert('File not found.');</script>");
                    }
                }
                else
                {
                    // Handle empty filename scenario
                    Response.Write("<script>alert('Invalid file.');</script>");
                }
            }
        }
    }
}
