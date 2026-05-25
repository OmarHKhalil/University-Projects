<%@ Page Title="" Language="C#" MasterPageFile="~/Site1.Master" AutoEventWireup="true" CodeBehind="editinfo.aspx.cs" Inherits="ppppppppppppppppppp.editinfo" %>
<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
<div class="page-title-container">
        <h2 class="page-title">Edit Project Information</h2>
    </div>  <form id="form1" runat="server" class="form-container">
        <asp:Label ID="Label1" runat="server" Text="Enter Project ID:" CssClass="label-style"></asp:Label>
        <br />
        <asp:TextBox ID="TextBox1" runat="server" CssClass="textbox-style" placeholder="Project ID"></asp:TextBox>
        <br />
        <asp:Label ID="Label2" runat="server" Text="Enter Project Name:" CssClass="label-style"></asp:Label>
        <br />
        <asp:TextBox ID="TextBox2" runat="server" CssClass="textbox-style" placeholder="Project Name"></asp:TextBox>
        <br />
        <asp:Label ID="Label3" runat="server" Text="Enter Description:" CssClass="label-style"></asp:Label>
        <br />
        <asp:TextBox ID="TextBox3" runat="server" CssClass="textbox-style" TextMode="MultiLine" placeholder="Project Description"></asp:TextBox>
        <br />
        <asp:Label ID="Label4" runat="server" Text="Upload File:" CssClass="label-style"></asp:Label>
        <br />
        <asp:FileUpload ID="FileUpload1" runat="server" CssClass="file-upload-style" />
        <br />
        <asp:Label ID="Label5" runat="server" Text="Upload Image:" CssClass="label-style"></asp:Label>
        <br />
        <asp:FileUpload ID="FileUpload2" runat="server" CssClass="file-upload-style" />
        <br />
        <br />
        <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="Submit" CssClass="button-style" />
    </form>

    <style type="text/css">
        body {
            font-family: Arial, sans-serif;
            background-color: #f4f4f9;
            margin: 0;
            padding: 0;
        }

        .form-container {
            background-color: #ffffff;
            padding: 30px;
            border-radius: 15px;
            box-shadow: 0 4px 20px rgba(0, 0, 0, 0.1);
            max-width: 600px;
            margin: 50px auto;
            border: 1px solid #ddd;
        }

        .label-style {
            display: block;
            margin-bottom: 10px;
            font-weight: bold;
            color: #333;
        }

        .textbox-style {
            width: 100%;
            padding: 12px;
            margin-bottom: 20px;
            border: 1px solid #ccc;
            border-radius: 8px;
            box-sizing: border-box;
            font-size: 14px;
            color: #555;
            transition: border-color 0.3s;
        }

        .textbox-style:focus {
            border-color: #3498db;
            outline: none;
            box-shadow: 0 0 6px rgba(52, 152, 219, 0.3);
        }

        .file-upload-style {
            display: block;
            margin-bottom: 20px;
            font-size: 14px;
        }

       .button-style {
            background-color: #3498db;
            color: white;
            padding: 12px 20px;
            border: none;
            border-radius: 8px;
            cursor: pointer;
            font-size: 16px;
            width: 25%;
            margin: 0 auto;
            display: block;
            transition: background-color 0.3s, transform 0.2s;
        }

        .button-style:hover {
            background-color: #2980b9;
            transform: scale(1.02);
        }

        .button-style:active {
            transform: scale(0.98);
        }
       .page-title-container {
            display: flex;
            justify-content: center;  /* لتوسيط العنصر أفقيًا */
        }

        .page-title {
            font-size: 24px;
            font-weight: bold;
        }

    </style>
</asp:Content>
