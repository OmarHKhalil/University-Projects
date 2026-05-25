<%@ Page Title="" Language="C#" MasterPageFile="~/Site1.Master" AutoEventWireup="true" CodeBehind="addproject.aspx.cs" Inherits="ppppppppppppppppppp.addproject" %>
<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
  <form id="form1" runat="server">
        <div class="project-form-container">
            <h2>Add Project</h2>
            <div class="form-group">
            <asp:Label ID="Label1" runat="server" Text="Project ID" CssClass="form-label"></asp:Label>
            <asp:TextBox ID="TextBox1" runat="server" CssClass="form-control"></asp:TextBox>
            <asp:Label ID="lblProjectIDError" runat="server" CssClass="error-label" ForeColor="Red"></asp:Label>
        </div>

        <div class="form-group">
            <asp:Label ID="Label2" runat="server" Text="Project Name" CssClass="form-label"></asp:Label>
            <asp:TextBox ID="TextBox2" runat="server" CssClass="form-control"></asp:TextBox>
            <asp:Label ID="lblProjectNameError" runat="server" CssClass="error-label" ForeColor="Red"></asp:Label>
        </div>

        <div class="form-group">
            <asp:Label ID="Label3" runat="server" Text="Project Description" CssClass="form-label"></asp:Label>
            <asp:TextBox ID="TextBox3" runat="server" CssClass="form-control" TextMode="MultiLine" Rows="4"></asp:TextBox>
            <asp:Label ID="lblDescriptionError" runat="server" CssClass="error-label" ForeColor="Red"></asp:Label>
        </div>

        <div class="form-group">
            <asp:Label ID="Label4" runat="server" Text="Requirements File" CssClass="form-label"></asp:Label>
            <asp:FileUpload ID="FileUpload1" runat="server" CssClass="form-control-file" />
            <asp:Label ID="lblFileUpload1Error" runat="server" CssClass="error-label" ForeColor="Red"></asp:Label>
        </div>

        <div class="form-group">
            <asp:Label ID="Label5" runat="server" Text="Project Image" CssClass="form-label"></asp:Label>
            <asp:FileUpload ID="FileUpload2" runat="server" CssClass="form-control-file" />
            <asp:Label ID="lblFileUpload2Error" runat="server" CssClass="error-label" ForeColor="Red"></asp:Label>
        </div>

            <div class="form-group submit-container">
                <asp:Button ID="submitButton" runat="server" Text="Submit" CssClass="btn submit-btn" OnClick="submitButton_Clic" />
            </div>
        </div>
    </form>
    
    <style type="text/css">
        .project-form-container {
            max-width: 600px;
            margin: 20px auto;
            padding: 30px;
            border: 1px solid #ddd;
            border-radius: 8px;
            background-color: #f9f9f9;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
        }

        .project-form-container h2 {
            text-align: center;
            margin-bottom: 30px;
            color: #333;
        }

        .form-group {
            margin-bottom: 20px;
        }

        .form-group.submit-container {
            text-align: center;
        }

        .form-label {
            display: block;
            margin-bottom: 5px;
            font-weight: 600;
            color: #555;
        }

        .form-control {
            width: 100%;
            padding: 10px;
            border: 1px solid #ccc;
            border-radius: 4px;
            font-size: 16px;
            box-sizing: border-box;
            transition: border-color 0.2s;
        }

        .form-control:focus {
            border-color: #007bff;
            outline: none;
            box-shadow: 0 0 0 0.2rem rgba(0, 123, 255, 0.25);
        }

        .form-control-file {
            display: block;
            padding: 10px 0;
            border: 2px dashed #ccc;
            border-radius: 4px;
            text-align: center;
            cursor: pointer;
            position: relative;
            transition: border-color 0.3s, background-color 0.3s;
        }

        .form-control-file:hover {
            border-color: #007bff;
            background-color: #f0f8ff;
        }

        .custom-file-upload {
            position: relative;
        }

        .file-upload-icon {
            position: absolute;
            right: 10px;
            top: 50%;
            transform: translateY(-50%);
            font-size: 20px;
            color: #007bff;
        }

        .btn.submit-btn {
            background-color: #007bff;
            color: white;
            border: none;
            border-radius: 4px;
            padding: 12px 20px;
            cursor: pointer;
            font-size: 16px;
            transition: background-color 0.2s;
        }

        .btn.submit-btn:hover {
            background-color: #0056b3;
        }
    </style>
</asp:Content>
