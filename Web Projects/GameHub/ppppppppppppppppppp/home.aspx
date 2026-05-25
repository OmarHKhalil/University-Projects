<%@ Page Title="" Language="C#" MasterPageFile="~/Site1.Master" AutoEventWireup="true" CodeBehind="home.aspx.cs" Inherits="ppppppppppppppppppp.home" %>
<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    <form id="form1" runat="server">

    <!-- Hero Section -->
    <section class="hero">
        <div class="hero-buttons">

            <asp:Button ID="Button1" runat="server" Text="log in" CssClass="btn login-btn" OnClick="Button1_Click"  />
<asp:Button ID="Button2" runat="server" Text="log out" CssClass="btn logout-btn" OnClick="Button2_Click"  />
                        </div>
        <div class="container">
                

            <h1>Discover Your Next Favorite Game</h1>
            <p>Explore the best collection of games and exclusive deals</p>
            <a href="store.aspx" class="btn">Explore  news about games</a>
           
       

              
            </div>/script>
    </section>
 


    <section class="section">
        <div class="container">
            <h2 class="section-title">new games</h2>
            <div class="card-container">
                <div class="card">
                    <span class="badge">-20%</span>
                    <img src="" alt="Shadow Realms">
                    <div class="card-info">
                        <h3 class="card-title">Shadow Realms</h3>
                        <p class="card-category">Category: Adventure</p> 
                    </div>
                    <p class="card-price">$34.99</p>
                </div>
                <div class="card">
                    <span class="badge">New</span>
                    <img src="" alt="Ethereal Odyssey">
                    <div class="card-info">
                        <h3 class="card-title">Ethereal Odyssey</h3>
                        <p class="card-category">Category: Action</p>
                    </div>
                    <p class="card-price">$41.99</p>
                </div>
                <div class="card">
                    <span class="badge">-10%</span>
                    <img src="" alt="Fantasy Quest">
                    <div class="card-info">
                        <h3 class="card-title">Fantasy Quest</h3>
                        <p class="card-category">Category: Fantasy</p>
                    </div>
                    <p class="card-price">$2.99</p>
                </div>
                 <div class="card">
                    <span class="badge">-10%</span>
                    <img src="" alt="Starlight Race">
                    <div class="card-info">
                        <h3 class="card-title">Starlight Racel</h3>
                        <p class="card-category">Category: Fantasy</p>
                    </div>
                    <p class="card-price">$27.99</p>
                </div>
                <div class="card">
                    <span class="badge">Hot</span>
                    <img src="" alt="Battle Royale">
                    <div class="card-info">
                        <h3 class="card-title">Battle Royale</h3>
                        <p class="card-category">Category: Action</p>
                    </div>
                    <p class="card-price">$33.99</p>
                </div>
            </div>
        </div>
    </section>
  

    <!-- Cards Section -->
    <section class="section">
        <div class="container">
            <h2 class="section-title">Trending Games</h2>
            <div class="card-container">
                <div class="card">
                    <span class="badge">-20%</span>
                    <img src="image\hightech-hiking-hikers-exploring-trails-with-wearable-tech_1168612-118651.jpg" alt="Cyber Adventure">
                    <div class="card-info">
                        <h3 class="card-title">Cyber Adventure</h3>
                        <p class="card-category">Category: Adventure</p> 
                    </div>
                    <p class="card-price">$39.99</p>
                </div>
                <div class="card">
                    <span class="badge">New</span>
                    <img src="image\cosmic-man-with-outer-space-background_839169-22610.jpg" alt="Galaxy Warriors">
                    <div class="card-info">
                        <h3 class="card-title">Galaxy Warriors</h3>
                        <p class="card-category">Category: Action</p>
                    </div>
                    <p class="card-price">$49.99</p>
                </div>
                <div class="card">
                    <span class="badge">-10%</span>
                    <img src="image\tilt-shift-medieval-fantasy-landscape_23-2150916602.jpg" alt="Fantasy Quest">
                    <div class="card-info">
                        <h3 class="card-title">Fantasy Quest</h3>

                        <p class="card-category">Category: Fantasy</p>
                    </div>
                    <p class="card-price">$29.99</p>
                </div>
                <div class="card">
                    <span class="badge">Hot</span>
                    <img src="image\close-up-portrait-baseball-player_23-2150885247.jpg" alt="Battle Royale">
                    <div class="card-info">
                        <h3 class="card-title">Battle Royale</h3>
                        <p class="card-category">Category: Action</p>
                    </div>
                    <p class="card-price">$19.99</p>
                </div>
            </div>
        </div>
    </section>
        <!-- Enhanced Advertisements Section -->
        <section class="ads-section">
            <div class="container">
                <h2 class="section-title">Exciting Project Announcements</h2>
                <div class="ads-slider">
                    <!-- Ad 1 -->
                    <div class="ad-card">
                        <img src="image\DALL·E-2024-12-21-14.02.png" alt="Project 1" class="ad-image">
                        <div class="ad-content">
                            <h3 class="ad-title">Skybound Adventures</h3>
                            <p class="ad-description">A thrilling journey through uncharted skies.</p>
                            <p class="ad-description">project id : 22</p>
                            <a href="addrequest.aspx" class="ad-link">Apply Now</a>
                        </div>
                    </div>
                    <!-- Ad 2 -->
                    <div class="ad-card">
                        <img src="image\DALL·E-2024-12-21-14.03.png" alt="Project 2" class="ad-image">
                        <div class="ad-content">
                            <h3 class="ad-title">Mystic Realms</h3>
                            <p class="ad-description">Embark on a mystical quest in a fantasy world.</p>
                             <p class="ad-description">project id : 33</p>
                            <a href="addrequest.aspx" class="ad-link">Apply Now</a>
                        </div>
                    </div>
                    <!-- Ad 3 -->
                    <div class="ad-card">
                        <img src="image\DALL·E-2024-12-21-14.04.png" alt="Project 3" class="ad-image">
                        <div class="ad-content">
                            <h3 class="ad-title">Galactic Wars</h3>
                            <p class="ad-description">Join the battle for galactic supremacy.</p>
                            <p class="ad-description">project id : 44</p>

                            <a href="addrequest.aspx" class="ad-link">Apply Now</a>
                        </div>
                    </div>
                </div>
            </div>
        </section>
        <style>
            /* Dropdown Styling */
           /* إعادة تعيين بعض الأنماط الأساسية */
* {
    margin: 0;
    padding: 0;
    box-sizing: border-box;
}

body {
    font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
    background-color: #f9f9f9;
    color: #333;
}

/* الحاوية العامة */
.container {
    width: 90%;
    max-width: 1200px;
    margin: 0 auto;
    padding: 20px 0;
}

/* قسم الهيرو */
.hero {
    background: linear-gradient(135deg, #6e8efb, #a777e3);
    color: #fff;
    padding: 100px 0;
    text-align: center;
    border-radius: 10px;
}

.hero h1 {
    font-size: 48px;
    margin-bottom: 20px;
}

.hero p {
    font-size: 18px;
    margin-bottom: 30px;
}

.btn {
    display: inline-block;
    padding: 12px 30px;
    background-color: #ff7f50;
    color: #fff;
    text-decoration: none;
    border-radius: 25px;
    transition: background-color 0.3s ease;
}

.btn:hover {
    background-color: #ff5722;
}



/* أقسام الألعاب */
.section {
    padding: 60px 0;
}

.section-title {
    font-size: 32px;
    text-align: center;
    margin-bottom: 40px;
    color: #2c3e50;
}

.card-container {
    display: flex;
    flex-wrap: wrap;
    justify-content: center;
    gap: 20px;
}

.card {
    background: #fff;
    border-radius: 10px;
    box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
    width: 250px;
    overflow: hidden;
    transition: transform 0.3s, box-shadow 0.3s;
}

.card:hover {
    transform: translateY(-10px);
    box-shadow: 0 12px 16px rgba(0, 0, 0, 0.2);
}

.badge {
    position: absolute;
    top: 10px;
    left: 10px;
    background-color: #e74c3c;
    color: #fff;
    padding: 5px 10px;
    border-radius: 5px;
    font-size: 12px;
}

.badge.discount {
    background-color: #e74c3c;
}

.badge.new {
    background-color: #27ae60;
}

.card img {
    width: 100%;
    height: 150px;
    object-fit: cover;
}

.card-info {
    padding: 15px;
    text-align: center;
}

.card-title {
    font-size: 20px;
    margin-bottom: 10px;
    color: #2c3e50;
}

.card-category {
    font-size: 14px;
    color: #7f8c8d;
}

.card-price {
    padding: 15px;
    font-size: 18px;
    font-weight: bold;
    text-align: center;
    background-color: #f1f1f1;
    color: #2c3e50;
}

/* قسم الإعلانات */
.ads-section {
    margin-top: 60px;
    padding: 60px 20px;
    background: linear-gradient(135deg, #e3f2fd, #bbdefb);
    border-radius: 15px;
    box-shadow: 0 4px 8px rgba(0, 0, 0, 0.2);
    text-align: center;
}

.ads-slider {
    display: flex;
    gap: 20px;
    overflow-x: auto;
    padding: 20px 0;
}

.ad-card {
    background: #ffffff;
    border-radius: 10px;
    box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1);
    padding: 20px;
    min-width: 300px;
    text-align: center;
    transition: transform 0.3s;
    flex: 0 0 auto;
}

.ad-card:hover {
    transform: scale(1.05);
}

.ad-image {
    width: 100%;
    height: 200px;
    object-fit: cover;
    border-radius: 10px;
    margin-bottom: 15px;
}

.ad-title {
    font-size: 20px;
    font-weight: bold;
    margin-bottom: 10px;
    color: #2c3e50;
}

.ad-description {
    font-size: 14px;
    margin-bottom: 15px;
    color: #555;
}

.ad-link {
    display: inline-block;
    padding: 10px 20px;
    background: #007bff;
    color: #fff;
    text-decoration: none;
    border-radius: 5px;
    transition: background 0.3s;
}

.ad-link:hover {
    background: #0056b3;
}

/* تحسين الاستجابة */
@media (max-width: 768px) {
    .hero h1 {
        font-size: 32px;
    }

    .hero p {
        font-size: 16px;
    }

    .card-container {
        flex-direction: column;
        align-items: center;
    }

    .ads-slider {
        flex-direction: column;
        align-items: center;
    }

    .ad-card {
        width: 100%;
        max-width: 300px;
    }
}

        </style>
       <style>
    /* الأزرار الجديدة */
  .hero-buttons {
            position: absolute; /* جعل الأزرار مطلقة داخل الحاوية */
            top: 20px; /* ضبط المسافة من الأعلى */
            left: 20px; /* ضبط المسافة من اليسار */
            /* إزالة margin-top لأننا نستخدم position absolute */
            margin-top: 0;
        }

        .login-btn {
            background-color: #28a745;
            color: #fff;
            border: none;
            padding: 10px 20px;
            border-radius: 5px;
            cursor: pointer;
            transition: background-color 0.3s ease;
            font-size: 16px;
        }

        .login-btn:hover {
            background-color: #218838;
        }

        .logout-btn {
            background-color: #dc3545;
            color: #fff;
            border: none;
            padding: 10px 20px;
            border-radius: 5px;
            cursor: pointer;
            transition: background-color 0.3s ease;
            font-size: 16px;
        }

        .logout-btn:hover {
            background-color: #c82333;
        }
</style>

    </form>

</asp:Content>

