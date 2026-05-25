<%@ Page Title="" Language="C#" MasterPageFile="~/Site1.Master" AutoEventWireup="true" CodeBehind="community.aspx.cs" Inherits="ppppppppppppppppppp.community" %>
<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    <style>
        .community-container {
            font-family: 'Segoe UI', sans-serif;
            margin: 20px auto;
            padding: 30px;
            max-width: 900px;
            background: linear-gradient(to bottom right, #f0f4c3, #b2dfdb);
            border-radius: 15px;
            box-shadow: 0 6px 15px rgba(0, 0, 0, 0.2);
        }
        .community-container h1 {
            color: #004d40;
            font-size: 3rem;
            text-align: center;
            margin-bottom: 20px;
        }
        .community-container p {
            font-size: 1.3rem;
            color: #37474f;
            margin-bottom: 20px;
            line-height: 1.8;
            text-align: center;
        }
        .community-container .community-actions {
            display: flex;
            flex-wrap: wrap;
            justify-content: space-around;
            margin-top: 20px;
        }
        .community-container .action {
            background-color: #ffffff;
            border: 2px solid #004d40;
            border-radius: 10px;
            padding: 20px;
            margin: 10px;
            flex: 0 0 calc(45% - 20px);
            text-align: center;
            transition: transform 0.3s, box-shadow 0.3s;
        }
        .community-container .action:hover {
            transform: translateY(-5px);
            box-shadow: 0 8px 20px rgba(0, 0, 0, 0.2);
        }
        .community-container .action h3 {
            color: #004d40;
            font-size: 1.5rem;
            margin-bottom: 10px;
        }
        .community-container .action p {
            font-size: 1rem;
            color: #37474f;
            margin-bottom: 10px;
        }
        .community-container .action a {
            text-decoration: none;
            color: #004d40;
            font-weight: bold;
        }
        .community-container .action a:hover {
            text-decoration: underline;
        }
    </style>
    <div class="community-container">
        <h1>Welcome to Our Community</h1>
        <p>Connect, collaborate, and grow with like-minded individuals in our vibrant community.</p>
        <div class="community-actions">
            <div class="action">
                <h3>Join Discussions</h3>
                <p>Participate in forums and share your ideas with the community.</p>
                <a href="#">Explore Forums</a>
            </div>
            <div class="action">
                <h3>Attend Events</h3>
                <p>Be part of our engaging events and webinars.</p>
                <a href="#">View Events</a>
            </div>
            <div class="action">
                <h3>Contribute</h3>
                <p>Support projects and initiatives that make a difference.</p>
                <a href="#">Learn More</a>
            </div>
            <div class="action">
                <h3>Give Feedback</h3>
                <p>Help us improve by sharing your valuable feedback.</p>
                <a href="#">Submit Feedback</a>
            </div>
        </div>
    </div>
</asp:Content>
