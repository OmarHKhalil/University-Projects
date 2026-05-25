<%@ Page Title="" Language="C#" MasterPageFile="~/Site1.Master" AutoEventWireup="true" CodeBehind="search and download.aspx.cs" Inherits="ppppppppppppppppppp.search_and_download" %>
<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">

    <form id="form1" runat="server">
        <style>
            body {
                font-family: Arial, sans-serif;
                background-color: #f9f9f9;
            }
            form {
                background-color: #fff;
                padding: 20px;
                border-radius: 10px;
                box-shadow: 0px 4px 6px rgba(0, 0, 0, 0.1);
                max-width: 800px;
                margin: auto;
            }
            h2 {
                text-align: center;
                color: #333;
            }
            label {
                display: block;
                margin-bottom: 5px;
                color: #555;
            }
           #TextBox1 {
                width: 100%;
                padding: 10px;
                border: 2px solid #007BFF;
                border-radius: 5px;
                margin-bottom: 20px;
                font-size: 16px;
                background-color: #f0f8ff;
                color: #333;
                box-shadow: 0px 2px 4px rgba(0, 0, 0, 0.1);
                transition: border-color 0.3s ease, box-shadow 0.3s ease;
            }
            #TextBox1:focus {
                border-color: #0056b3;
                box-shadow: 0px 4px 6px rgba(0, 0, 0, 0.2);
                outline: none;
            }
           
            .gridview {
                margin-top: 20px;
                border: 1px solid #ddd;
                border-radius: 5px;
                overflow: hidden;
            }
            .gridview th {
                background-color: #007BFF;
                color: white;
                font-weight: bold;
            }
            .gridview td, .gridview th {
                padding: 10px;
                text-align: left;
                border-bottom: 1px solid #ddd;
            }
            .gridview img {
                height: 50px;
                width: 50px;
                border: 1px solid #ccc;
            }
            .download-button {
                background-color: #28a745;
                color: white;
                border: none;
                padding: 5px 10px;
                text-align: center;
                text-decoration: none;
                display: inline-block;
                font-size: 14px;
                margin: 2px 1px;
                cursor: pointer;
                border-radius: 5px;
            }
            .search-button {
    width: 10%;
    padding: 12px;
    border: none;
    border-radius: 5px;
    background-color: #28a745;
    color: white;
    font-size: 16px;
    cursor: pointer;
    box-shadow: 0px 4px 6px rgba(0, 0, 0, 0.1);
    transition: background-color 0.3s ease, transform 0.2s ease;
}
.search-button:hover {
    background-color: #218838;
    transform: scale(1.05);
}
.search-button:active {
    background-color: #1e7e34;
    transform: scale(0.98);
}
/* تصميم TextBox */
.custom-textbox {
    width: 40%;
    padding: 12px;
    font-size: 16px;
    border: 2px solid #007BFF;
    border-radius: 5px;
    background-color: #f0f8ff;
    color: #333;
    box-shadow: 0px 2px 4px rgba(0, 0, 0, 0.1);
    transition: border-color 0.3s ease, box-shadow 0.3s ease;
}

.custom-textbox:focus {
    border-color: #0056b3;
    box-shadow: 0px 4px 6px rgba(0, 0, 0, 0.2);
    outline: none;
}

/* تصميم الزر */
.custom-button {
    width: 100%;
    padding: 12px;
    font-size: 16px;
    border: none;
    border-radius: 5px;
    background-color: #28a745;
    color: white;
    cursor: pointer;
    box-shadow: 0px 4px 6px rgba(0, 0, 0, 0.1);
    transition: background-color 0.3s ease, transform 0.2s ease;
}

.custom-button:hover {
    background-color: #218838;
    transform: scale(1.05);
}

.custom-button:active {
    background-color: #1e7e34;
    transform: scale(0.98);
}

        </style>

        <h2>Search and Download Projects</h2>

        <div>
            <label for="TextBox1">Enter Project ID:</label>
<asp:TextBox ID="TextBox1" runat="server" CssClass="custom-textbox"></asp:TextBox>
        </div>

<asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="Search" CssClass="search-button" />

        <asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="False" DataKeyNames="ProjectID,RequirementsFile" DataSourceID="SqlDataSource2" OnRowCommand="GridView1_RowCommand" Visible="False" CssClass="gridview">
            <HeaderStyle CssClass="gridview-header" />
            <Columns>
                <asp:BoundField DataField="ProjectID" HeaderText="Project ID" ReadOnly="True" SortExpression="ProjectID" />
                <asp:BoundField DataField="ProjectName" HeaderText="Project Name" SortExpression="ProjectName" />
                <asp:BoundField DataField="ProjectDescription" HeaderText="Description" SortExpression="ProjectDescription" />
                <asp:BoundField DataField="DepartmentID" HeaderText="Department" SortExpression="DepartmentID" />
                <asp:BoundField DataField="ProjectManagerID" HeaderText="Manager" SortExpression="ProjectManagerID" />
                <asp:ImageField DataImageUrlField="ProjectImage" HeaderText="Project Image">
                    <ControlStyle CssClass="gridview-image" />
                </asp:ImageField>
               <asp:TemplateField HeaderText="Requirement File">
    <ItemTemplate>
        <div class="requirement-image">
            <img src="image\OIP_10.jpeg" alt="PDF File" />
        </div>
    </ItemTemplate>
</asp:TemplateField>
                <asp:ButtonField ButtonType="Button" CommandName="download" HeaderText="Download File" Text="Download" ItemStyle-CssClass="download-button" />
            </Columns>
        </asp:GridView>

        <asp:SqlDataSource ID="SqlDataSource2" runat="server" ConnectionString="<%$ ConnectionStrings:ConnectionString %>" SelectCommand="SELECT * FROM [Projects] WHERE ([ProjectID] = @ProjectID)">
            <SelectParameters>
                <asp:ControlParameter ControlID="TextBox1" Name="ProjectID" PropertyName="Text" Type="Int32" />
            </SelectParameters>
        </asp:SqlDataSource>
    </form>

</asp:Content>
