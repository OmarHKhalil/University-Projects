<%@ Page Title="" Language="C#" MasterPageFile="~/Site1.Master" AutoEventWireup="true" CodeBehind="manage.aspx.cs" Inherits="ppppppppppppppppppp.manage" %>
<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">

   <form id="form1" runat="server">
    <asp:GridView ID="GridView1" runat="server" CssClass="styled-gridview" AutoGenerateColumns="False" DataKeyNames="RequestID" OnRowCommand="GridView1_RowCommand" EmptyDataText="No data available." >
            <Columns>
                <asp:BoundField DataField="RequestID" HeaderText="RequestID" InsertVisible="False" ReadOnly="True" SortExpression="RequestID" />
                <asp:BoundField DataField="EmployeeID" HeaderText="EmployeeID" SortExpression="EmployeeID" />
                <asp:BoundField DataField="Skill1" HeaderText="Skill1" SortExpression="Skill1" />
                <asp:BoundField DataField="Skill2" HeaderText="Skill2" SortExpression="Skill2" />
                <asp:BoundField DataField="Skill3" HeaderText="Skill3" SortExpression="Skill3" />
                <asp:BoundField DataField="TotalPoints" HeaderText="TotalPoints" SortExpression="TotalPoints" />
                <asp:BoundField DataField="ProjectID" HeaderText="ProjectID" SortExpression="ProjectID" />
                <asp:BoundField DataField="the Role" HeaderText="The Role" SortExpression="the Role" />
                <asp:TemplateField>
                    <ItemTemplate>
<asp:Button ID="AcceptButton" runat="server" CommandName="Accept" Text="✔ Accept" CssClass="accept-button" CommandArgument='<%# Container.DataItemIndex %>' />                    </ItemTemplate>
                </asp:TemplateField>
                <asp:TemplateField>
                    <ItemTemplate>
<asp:Button ID="RejectButton" runat="server" CommandName="Reject" Text="✘ Reject" CssClass="reject-button" CommandArgument='<%# Container.DataItemIndex %>' />                    </ItemTemplate>
                </asp:TemplateField>
            </Columns>
        </asp:GridView>
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:ConnectionString %>" SelectCommand="SELECT * FROM [Requests]" OnSelecting="SqlDataSource1_Selecting"></asp:SqlDataSource>
    <asp:GridView ID="GridView2" runat="server" CssClass="styled-gridview-secondary" AutoGenerateColumns="False" DataKeyNames="RequestID" DataSourceID="SqlDataSource2" EmptyDataText="No data available.">
        <Columns>
            <asp:BoundField DataField="RequestID" HeaderText="RequestID" ReadOnly="True" SortExpression="RequestID" />
            <asp:BoundField DataField="EmployeeID" HeaderText="EmployeeID" SortExpression="EmployeeID" />
            <asp:BoundField DataField="ProjectID" HeaderText="ProjectID" SortExpression="ProjectID" />
            <asp:BoundField DataField="the Role" HeaderText="the Role" SortExpression="the Role" />
            <asp:BoundField DataField="the status" HeaderText="the status" SortExpression="the status" />
        </Columns>
    </asp:GridView>
    <asp:SqlDataSource ID="SqlDataSource2" runat="server" ConnectionString="<%$ ConnectionStrings:ConnectionString %>" SelectCommand="SELECT * FROM [TemporaryRequests]"></asp:SqlDataSource>

    <br />
    <asp:Button ID="Button2" runat="server" Text="Submit" CssClass="styled-button" OnClick="Button2_Click" />

    </form>
    <style>
        .styled-gridview {
            width: 100%;
            border: 1px solid #ccc;
            border-collapse: collapse;
        }

        .styled-gridview th {
            background-color: #f4f4f4;
            padding: 10px;
            text-align: left;
            border-bottom: 1px solid #ddd;
        }

        .styled-gridview td {
            padding: 10px;
            border-bottom: 1px solid #ddd;
        }

        .styled-gridview-secondary {
            width: 80%;
            border: 1px solid #888;
            margin-top: 20px;
            border-collapse: collapse;
        }

        .styled-gridview-secondary th {
            background-color: #e4e4e4;
            color: #333;
            padding: 8px;
            text-align: left;
        }

        .styled-gridview-secondary td {
            padding: 8px;
            border-bottom: 1px solid #bbb;
        }

        .accept-button {
            color: white;
            background-color: #28a745;
            border: none;
            padding: 5px 10px;
            cursor: pointer;
            border-radius: 4px;
        }

        .reject-button {
            color: white;
            background-color: #dc3545;
            border: none;
            padding: 5px 10px;
            cursor: pointer;
            border-radius: 4px;
        }

        .styled-button {
            display: inline-block;
            padding: 10px 20px;
            color: #fff;
            background-color: #007bff;
            border: none;
            border-radius: 5px;
            cursor: pointer;
        }

        .styled-button:hover {
            background-color: #0056b3;
        }

    </style>
    <style>
        body {
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
            margin: 0;
            padding: 0;
            background-color: #f8f9fa;
        }

        .styled-gridview {
            width: 70%;
            margin: 20px auto;
            border-collapse: collapse;
            font-size: 16px;
            box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);
            border-radius: 8px;
            overflow: hidden;
        }

        .styled-gridview th {
            background-color: #343a40;
            color: #fff;
            text-align: center;
            padding: 12px;
            font-size: 18px;
        }

        .styled-gridview td {
            padding: 10px;
            text-align: center;
            border-bottom: 1px solid #ddd;
        }

        .styled-gridview tr:nth-child(even) {
            background-color: #f2f2f2;
        }

        .styled-gridview tr:hover {
            background-color: #e9ecef;
        }

        .accept-button {
            background-color: #28a745;
            color: white;
            border: none;
            padding: 10px 20px;
            cursor: pointer;
            font-size: 14px;
            border-radius: 5px;
            transition: background-color 0.3s;
        }

        .accept-button:hover {
            background-color: #218838;
        }

        .reject-button {
            background-color: #dc3545;
            color: white;
            border: none;
            padding: 10px 20px;
            cursor: pointer;
            font-size: 14px;
            border-radius: 5px;
            transition: background-color 0.3s;
        }

        .reject-button:hover {
            background-color: #c82333;
        }
    </style>
</asp:Content>
