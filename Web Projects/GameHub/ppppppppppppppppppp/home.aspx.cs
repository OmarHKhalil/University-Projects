using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace ppppppppppppppppppp
{
    public partial class home : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack) // التأكد من تحميل الصفحة لأول مرة فقط
            {
                UpdateButtonVisibility();
            }
        }

        private void UpdateButtonVisibility()
        {
            if (Session["IsLoggedIn"] != null && (bool)Session["IsLoggedIn"] == true)
            {
                // إظهار زر تسجيل الخروج وإخفاء زر تسجيل الدخول
                Button1.Visible = false; // Log In
                Button2.Visible = true;  // Log Out
            }
            else
            {
                // إظهار زر تسجيل الدخول وإخفاء زر تسجيل الخروج
                Button1.Visible = true;  // Log In
                Button2.Visible = false; // Log Out
            }
        
    }
        protected void submitButton_Click(object sender, EventArgs e)
        {

        }

        protected void submitButton_Clic(object sender, EventArgs e)
        {

        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            Response.Redirect("Log in.aspx");

        }

        protected void Button2_Click(object sender, EventArgs e)
        {
            // تسجيل خروج المستخدم
            Session["IsLoggedIn"] = null;

            // إعادة توجيه المستخدم إلى الصفحة الرئيسية
            Response.Redirect("home.aspx");
        }
    }
    }
