<%@ Page Title="" Language="C#" MasterPageFile="~/Site1.Master" AutoEventWireup="true" CodeBehind="gridviewproject.aspx.cs" Inherits="ppppppppppppppppppp.WebForm3" %>
<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">

    <form id="form1" runat="server">
        <asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="False" DataKeyNames="ProjectID" DataSourceID="SqlDataSource1" CssClass="styled-gridview" OnSelectedIndexChanged="GridView1_SelectedIndexChanged" EmptyDataText="No data available.">
            <Columns>
                <asp:BoundField DataField="ProjectID" HeaderText="Project ID" ReadOnly="True" SortExpression="ProjectID" ItemStyle-Width="80px" >
<ItemStyle Width="80px"></ItemStyle>
                </asp:BoundField>
                <asp:BoundField DataField="ProjectName" HeaderText="Project Name" SortExpression="ProjectName" ItemStyle-Width="150px" >
<ItemStyle Width="150px"></ItemStyle>
                </asp:BoundField>
                <asp:BoundField DataField="ProjectDescription" HeaderText="Project Description" SortExpression="ProjectDescription" ItemStyle-Width="250px">
<ItemStyle Width="250px"></ItemStyle>
                </asp:BoundField>
                <asp:TemplateField HeaderText="Project Image" ItemStyle-Width="80px" ItemStyle-HorizontalAlign="Center">
                  <ItemTemplate>
                    <asp:Image ID="imgProject" runat="server" ImageUrl='<%# Eval("ProjectImage") %>' Height="50px" Width="50px" />
                  </ItemTemplate>

<ItemStyle HorizontalAlign="Center" Width="80px"></ItemStyle>
                </asp:TemplateField>

                <asp:TemplateField HeaderText="Requirements File" ItemStyle-Width="80px" ItemStyle-HorizontalAlign="Center">
                    <ItemTemplate>
                      <a href='<%# Eval("RequirementsFile") %>' target="_blank">
                        <asp:Image ID="imgRequirements" runat="server" ImageUrl="image\OIP_11.jpeg" Height="50px" Width="50px" />
                      </a>
                   </ItemTemplate>

<ItemStyle HorizontalAlign="Center" Width="80px"></ItemStyle>
                </asp:TemplateField>


                <asp:BoundField DataField="ProjectManagerID" HeaderText="Project Manager ID" SortExpression="ProjectManagerID" ItemStyle-Width="80px">
                <ItemStyle Width="80px" />
                </asp:BoundField>


            </Columns>
            <HeaderStyle CssClass="grid-header" />
            <RowStyle CssClass="grid-row" />
        </asp:GridView>
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:ConnectionString %>" SelectCommand="SELECT * FROM [Projects]"></asp:SqlDataSource>
    </form>

    <style type="text/css">
       .styled-gridview {
            border-collapse: collapse;
            width: 100%;
            font-family: Arial, sans-serif;
            margin-top: 20px;
        }

        .styled-gridview th, .styled-gridview td {
            border: 1px solid #ddd;
            padding: 8px;
            text-align: left;
        }

        .grid-header {
            background-color: #f2f2f2;
            font-weight: bold;
        }

        .grid-row:nth-child(even) {
            background-color: #f9f9f9;
        }
    </style>

</asp:Content>