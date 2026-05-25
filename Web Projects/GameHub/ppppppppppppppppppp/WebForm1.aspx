<%@ Page Title="" Language="C#" MasterPageFile="~/Site1.Master" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="ppppppppppppppppppp.WebForm1" %>
<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">

    <form id="form1" runat="server">
        <asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="False" DataKeyNames="ProjectID" DataSourceID="SqlDataSource1">
            <Columns>
                <asp:BoundField DataField="ProjectID" HeaderText="ProjectID" ReadOnly="True" SortExpression="ProjectID" />
                <asp:BoundField DataField="ProjectName" HeaderText="ProjectName" SortExpression="ProjectName" />
                <asp:BoundField DataField="ProjectDescription" HeaderText="ProjectDescription" SortExpression="ProjectDescription" />
                <asp:BoundField DataField="RequirementsFile" HeaderText="RequirementsFile" SortExpression="RequirementsFile" />
                <asp:BoundField DataField="ProjectImage" HeaderText="ProjectImage" SortExpression="ProjectImage" />
                <asp:BoundField DataField="DepartmentID" HeaderText="DepartmentID" SortExpression="DepartmentID" />
                <asp:BoundField DataField="ProjectManagerID" HeaderText="ProjectManagerID" SortExpression="ProjectManagerID" />
            </Columns>
        </asp:GridView>
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:ConnectionString %>" SelectCommand="SELECT * FROM [Projects]"></asp:SqlDataSource>
    </form>

</asp:Content>
