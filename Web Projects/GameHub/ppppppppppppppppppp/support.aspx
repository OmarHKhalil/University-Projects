<%@ Page Title="" Language="C#" MasterPageFile="~/Site1.Master" AutoEventWireup="true" CodeBehind="support.aspx.cs" Inherits="ppppppppppppppppppp.support" %>
<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
     <style>
        .support-container {
            font-family: 'Segoe UI', sans-serif;
            margin: 20px auto;
            padding: 30px;
            max-width: 900px;
            background-color: #e8f1f9;
            border-radius: 10px;
            box-shadow: 0 6px 10px rgba(0, 0, 0, 0.15);
        }
        .support-container h1 {
            color: #2176c7;
            font-size: 2.5rem;
            margin-bottom: 20px;
        }
        .support-container p {
            font-size: 1.2rem;
            color: #555;
            margin-bottom: 20px;
            line-height: 1.8;
        }
        .support-container input,
        .support-container textarea,
        .support-container button {
            width: 100%;
            margin: 10px 0;
            padding: 12px;
            font-size: 1rem;
            border: 1px solid #ccc;
            border-radius: 5px;
        }
        .support-container button {
            background-color: #2176c7;
            color: #fff;
            border: none;
            cursor: pointer;
        }
        .support-container button:hover {
            background-color: #185a9d;
        }
    </style>
    <div class="support-container">
        <h1>Support</h1>
        <p>If you need assistance, please fill out the form below. Our support team will get back to you shortly.</p>
        <label for="email">Email Address:</label>
        <input id="email" type="email" placeholder="Enter your email..." />
        <label for="issue">Describe Your Issue:</label>
        <textarea id="issue" rows="5" placeholder="Describe your issue in detail..."></textarea>
        <button type="button">Submit</button>
    </div>
</asp:Content>
