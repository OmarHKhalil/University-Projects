<%@ Page Title="" Language="C#" MasterPageFile="~/Site1.Master" AutoEventWireup="true" CodeBehind="log in.aspx.cs" Inherits="ppppppppppppppppppp.log_in" %>
<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
         <!-- تأكد أن المحتوى داخل form tag -->
    <form id="loginForm" runat="server">
        <div style="width: 400px; margin: auto; padding: 30px; border: 1px solid #ddd; border-radius: 8px; box-shadow: 0px 0px 10px #ccc;">
            <h2 style="text-align: center; font-family: Arial, sans-serif;">Login</h2>

            <asp:Label ID="lblErrorMessage" runat="server" ForeColor="Red" Style="display: block; text-align: center; margin-bottom: 15px;"></asp:Label>

            <div style="margin-bottom: 15px;">
                <label for="txtUsername" style="display: block; font-weight: bold;">Username:</label>
                <asp:TextBox ID="txtUsername" runat="server" CssClass="form-control" Style="width: 100%; padding: 8px; border: 1px solid #ddd; border-radius: 4px;"></asp:TextBox>
            </div>

            <div style="margin-bottom: 15px;">
                <label for="txtPassword" style="display: block; font-weight: bold;">Password:</label>
                <asp:TextBox ID="txtPassword" runat="server" TextMode="Password" CssClass="form-control" Style="width: 100%; padding: 8px; border: 1px solid #ddd; border-radius: 4px;"></asp:TextBox>
            </div>

            <div style="text-align: center;">
                <asp:Button ID="btnLogin" runat="server" Text="Log In" OnClick="btnLogin_Click" CssClass="btn btn-primary" Style="padding: 10px 20px; border: none; border-radius: 4px; background-color: #007BFF; color: white; font-size: 16px; cursor: pointer;" />
            </div>
        </div>
    </form>
   
</asp:Content>
