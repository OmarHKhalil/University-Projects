<%@ Page Title="" Language="C#" MasterPageFile="~/Site1.Master" AutoEventWireup="true" CodeBehind="store.aspx.cs" Inherits="ppppppppppppppppppp.store" %>
<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    <style>
        .store-container {
            font-family: 'Segoe UI', sans-serif;
            margin: 20px auto;
            padding: 30px;
            max-width: 1200px;
            background-color: #fefefe;
            border-radius: 15px;
            box-shadow: 0 6px 15px rgba(0, 0, 0, 0.1);
        }
        .store-container h1 {
            color: #333;
            font-size: 3rem;
            text-align: center;
            margin-bottom: 20px;
        }
        .store-container .products {
            display: flex;
            flex-wrap: wrap;
            justify-content: space-between;
            gap: 20px;
        }
        .store-container .product {
            flex: 0 0 calc(25% - 20px);
            background-color: #fff;
            border: 1px solid #ddd;
            border-radius: 10px;
            padding: 15px;
            text-align: center;
            transition: transform 0.3s, box-shadow 0.3s;
        }
        .store-container .product:hover {
            transform: scale(1.05);
            box-shadow: 0 8px 20px rgba(0, 0, 0, 0.15);
        }
        .store-container .product img {
            max-width: 100%;
            border-radius: 10px;
            margin-bottom: 10px;
        }
        .store-container .product h3 {
            color: #555;
            font-size: 1.5rem;
            margin: 10px 0;
        }
        .store-container .product p {
            color: #777;
            font-size: 1rem;
            margin-bottom: 15px;
        }
        .store-container .product button {
            background-color: #2176c7;
            color: #fff;
            border: none;
            padding: 10px 20px;
            font-size: 1rem;
            border-radius: 5px;
            cursor: pointer;
        }
        .store-container .product button:hover {
            background-color: #185a9d;
        }
    </style>
    <div class="store-container">
        <h1>Welcome to Our Store</h1>
        <div class="products">
            <div class="product">
                <img src="https://via.placeholder.com/150" alt="Product 1">
                <h3>Product 1</h3>
                <p>$19.99</p>
                <button>Add to Cart</button>
            </div>
            <div class="product">
                <img src="https://via.placeholder.com/150" alt="Product 2">
                <h3>Product 2</h3>
                <p>$29.99</p>
                <button>Add to Cart</button>
            </div>
            <div class="product">
                <img src="https://via.placeholder.com/150" alt="Product 3">
                <h3>Product 3</h3>
                <p>$39.99</p>
                <button>Add to Cart</button>
            </div>
            <div class="product">
                <img src="https://via.placeholder.com/150" alt="Product 4">
                <h3>Product 4</h3>
                <p>$49.99</p>
                <button>Add to Cart</button>
            </div>
            <div class="product">
                <img src="https://via.placeholder.com/150" alt="Product 5">
                <h3>Product 5</h3>
                <p>$59.99</p>
                <button>Add to Cart</button>
            </div>
            <div class="product">
                <img src="https://via.placeholder.com/150" alt="Product 6">
                <h3>Product 6</h3>
                <p>$69.99</p>
                <button>Add to Cart</button>
            </div>
            <div class="product">
                <img src="https://via.placeholder.com/150" alt="Product 7">
                <h3>Product 7</h3>
                <p>$79.99</p>
                <button>Add to Cart</button>
            </div>
            <div class="product">
                <img src="https://via.placeholder.com/150" alt="Product 8">
                <h3>Product 8</h3>
                <p>$89.99</p>
                <button>Add to Cart</button>
            </div>
        </div>
    </div>
</asp:Content>
