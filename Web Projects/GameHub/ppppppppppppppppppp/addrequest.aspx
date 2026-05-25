<%@ Page Title="" Language="C#" MasterPageFile="~/Site1.Master" AutoEventWireup="true" CodeBehind="addrequest.aspx.cs" Inherits="ppppppppppppppppppp.addrequest" %>
<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
   <div id="requestFormContainer" class="container">
        <h2 id="formTitle" class="text-center mb-4">Add New Request</h2>
        <form id="addRequestForm" runat="server" class="row g-3 justify-content-center">
             <div id="employeeTypeGroup" class="col-md-8">
                <label id="employeeTypeLabel" for="<%=EmployeeType.ClientID%>" class="form-label">Request For</label>
                <asp:DropDownList ID="EmployeeType" runat="server" CssClass="form-select" OnSelectedIndexChanged="EmployeeType_SelectedIndexChanged">
                    <asp:ListItem Text="Select Option" Value="" />
                    <asp:ListItem Text="Manager" Value="Manager" />
                    <asp:ListItem Text="Employee" Value="Employee" />
                </asp:DropDownList>
            </div>
            <div id="employeeIdGroup" class="col-md-8">
                <label id="employeeIdLabel" for="<%=EmployeeID.ClientID%>" class="form-label">Employee ID/label>
                <asp:TextBox ID="EmployeeID" runat="server" CssClass="form-control" placeholder="Enter Employee ID"></asp:TextBox>
            </div>

            <div id="category1Group" class="col-md-8">
                <label id="category1Label" for="<%=Category1.ClientID%>" class="form-label">Category 1</label>
                <asp:DropDownList ID="Category1" runat="server" CssClass="form-select">
                    <asp:ListItem Text="Select Technical Skills: 1" Value="" />
                    <asp:ListItem Text=" Proficiency in Programming Languages 1" Value="50" />
                    <asp:ListItem Text=" Understanding of Game Engines 2" Value="100" />
                    <asp:ListItem Text=" Problem-Solving Abilities 3" Value="150" />
                </asp:DropDownList>
            </div>

            <div id="category2Group" class="col-md-8">
                <label id="category2Label" for="<%=Category2.ClientID%>" class="form-label">Category 2</label>
                <asp:DropDownList ID="Category2" runat="server" CssClass="form-select">
                    <asp:ListItem Text="Select Soft & Collaborative Skills: 2" Value="" />
                    <asp:ListItem Text=" Effective Communication " Value="20" />
                    <asp:ListItem Text=" Teamwork and Collaboration " Value="40" />
                    <asp:ListItem Text=" Adaptability and Flexibility " Value="60" />
                </asp:DropDownList>
            </div>

            <div id="category3Group" class="col-md-8">
                <label id="category3Label" for="<%=Category3.ClientID%>" class="form-label">Category 3</label>
                <asp:DropDownList ID="Category3" runat="server" CssClass="form-select">
                    <asp:ListItem Text="Select Passion & Game Knowledge: 3" Value="" />
                    <asp:ListItem Text=" Passion for Games " Value="30" />
                    <asp:ListItem Text=" Knowledge of Game Design Principles " Value="50" />
                    <asp:ListItem Text=" Relevant Portfolio or Projects " Value="70" />
                </asp:DropDownList>
            </div>

            <div id="projectIdGroup" class="col-md-8">
                <label id="projectIdLabel" for="<%=ProjectID.ClientID%>" class="form-label">Project ID</label>
                <asp:TextBox ID="ProjectID" runat="server" CssClass="form-control" placeholder="Enter Project ID"></asp:TextBox>
            </div>

            <div id="submitButtonContainer" class="col-md-8 text-center mt-4">
<asp:Button ID="SubmitButton" runat="server" Text="Submit Request" CssClass="btn btn-primary btn-lg w-100 submit-button" OnClick="SubmitButton_Click" />            </div>
        </form>
    </div>
    <style>
        /* Design based on IDs */
       #requestFormContainer {
            max-width: 650px;
            margin: 40px auto;
            background-color: #f8f9fa;
            padding: 30px;
            border-radius: 10px;
            box-shadow: 0 5px 15px rgba(0, 0, 0, 0.1);
            /* إضافة هذه الخصائص لتوسيط المحتوى */
            display: flex;
            flex-direction: column;
            align-items: center;
        }

        #formTitle {
            color: #007bff;
            margin-bottom: 30px;
            font-size: 2.2rem;
        }

        .form-label {
            display: block;
            margin-bottom: 5px;
            font-weight: bold;
            color: #495057;
        }

        .form-control, .form-select {
            width: 85%;
            padding: 10px 15px;
            margin-bottom: 20px;
            border: 1px solid #ced4da;
            border-radius: 5px;
            box-sizing: border-box;
            font-size: 1rem;
        }

        .form-control:focus, .form-select:focus {
            border-color: #80bdff;
            box-shadow: 0 0 0 0.2rem rgba(0, 123, 255, 0.25);
            outline: 0;
        }

        .text-danger {
            color: #dc3545;
            font-size: 0.9rem;
            margin-top: -15px;
            margin-bottom: 15px;
            display: block;
        }

        .submit-button {
            background-color: #28a745;
            color: white;
            padding: 12px 25px;
            border: none;
            border-radius: 5px;
            cursor: pointer;
            font-size: 1.1rem;
            transition: background-color 0.3s ease;
            width: 85%; /* Make button full width within its container */
        }

        .submit-button:hover {
            background-color: #218838;
        }
    </style>
</asp:Content>
