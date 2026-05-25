<%@ Page Title="" Language="C#" MasterPageFile="~/Site1.Master" AutoEventWireup="true" CodeBehind="dbproject1.aspx.cs" Inherits="ppppppppppppppppppp.dbproject1" %>
<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    <div class="container">
        <!-- Header -->
        <header class="page-header">
            <div class="header-content">
                <h1>Projects Management </h1>
                <p>Manage your projects effectively with these tools</p>
            </div>
        </header>

        <!-- Navigation Links -->
        <nav class="main-nav">
            <ul class="nav-list">
                <li><a href="addproject.aspx" class="nav-item"><span>Add New Project</span><i class="fas fa-plus"></i></a></li>
                <li><a href="editinfo.aspx" class="nav-item"><span>Edit Project</span><i class="fas fa-edit"></i></a></li>
                <li><a href="gridviewproject.aspx" class="nav-item"><span>View Details</span><i class="fas fa-eye"></i></a></li>
            </ul>
        </nav>

        <style>
             /* Import Font Awesome for icons */
            @import url("https://cdnjs.cloudflare.com/ajax/libs/font-awesome/5.15.4/css/all.min.css");

            /* General Container Style */
           .container {
              max-width: 1200px;
              margin: 20px auto;
              padding: 0 20px;
            }
            /* Header Style */
             .page-header {
                background: linear-gradient(135deg, #3498db, #2c3e50); /* Gradient Background */
                color: #fff; /* White text on dark background */
                padding: 40px 0;
                text-align: center;
               margin-bottom: 30px;
                box-shadow: 0 4px 8px rgba(0,0,0,0.1); /* subtle box shadow for depth */
             }
            .header-content {
              max-width: 800px;
              margin: 0 auto;
            }

            .page-header h1 {
                margin-bottom: 10px;
                font-size: 2.5em; /* larger title */
                 text-shadow: 2px 2px 4px rgba(0, 0, 0, 0.3); /* title with shadow */
            }
           
            .page-header p {
                font-size: 1.2em;
                font-weight: 300;
                 text-shadow: 1px 1px 2px rgba(0, 0, 0, 0.2);
            }

            /* Navigation Styles */
            .main-nav {
                background-color: #f4f4f4; /* Light background for navigation */
                padding: 20px 0;
                 border-radius: 10px;
                 box-shadow: 0 2px 4px rgba(0,0,0,0.1);
            }

            .nav-list {
                list-style: none;
                padding: 0;
                display: flex;
                justify-content: space-around;
                flex-wrap: wrap;
            }

             .nav-item{
                 text-decoration: none;
                 background-color: #fff; /* Button Background Color */
                 color: #2c3e50;
                 padding: 15px 20px;
                margin: 10px;
                border-radius: 8px; /* Rounded borders for buttons */
                transition: transform 0.3s ease, box-shadow 0.3s ease;
                display: inline-flex;
                 align-items: center;
                 box-shadow: 0 2px 4px rgba(0,0,0,0.1);
                border: 1px solid #e0e0e0;
            }
           .nav-item:hover{
              background-color: #e0e0e0;
                transform: translateY(-3px); /* hover animation */
                 box-shadow: 0 4px 8px rgba(0,0,0,0.2); /* enhanced shadow on hover */

            }
            .nav-item span {
                margin-right: 10px;
                font-weight: 500;

            }
            /* Icons styles */
            .nav-item i {
                font-size: 1.2em; /* icon size */
            }


        </style>
    </div>
</asp:Content>