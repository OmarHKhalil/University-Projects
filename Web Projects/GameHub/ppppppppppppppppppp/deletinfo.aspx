<%@ Page Title="" Language="C#" MasterPageFile="~/Site1.Master" AutoEventWireup="true" CodeBehind="deletinfo.aspx.cs" Inherits="ppppppppppppppppppp.deletinfo" %>
<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">

   <form id="form1" runat="server" style="max-width: 400px; margin: auto; font-family: Arial, sans-serif; background-color: #f9f9f9; padding: 20px; border-radius: 8px; box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);">
        <h2 style="text-align: center; color: #333;">Delete Project</h2>
        <div style="margin-bottom: 20px;">
            <asp:Label ID="Label1" runat="server" Text="Enter Project ID:" style="display: block; font-size: 14px; color: #555; margin-bottom: 5px;"></asp:Label>
            <asp:TextBox ID="TextBox1" runat="server" style="width: 100%; padding: 8px; font-size: 14px; border: 1px solid #ccc; border-radius: 4px;"></asp:TextBox>
        </div>
        <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="Delete" style="width: 100%; padding: 10px; font-size: 16px; color: #fff; background-color: #d9534f; border: none; border-radius: 4px; cursor: pointer;" />
        <br />
        <br />
    </form>

</asp:Content>
