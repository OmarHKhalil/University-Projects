<%@ Page Title="" Language="C#" MasterPageFile="~/Site1.Master" AutoEventWireup="true" CodeBehind="WebForm4.aspx.cs" Inherits="ppppppppppppppppppp.WebForm4" %>
<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    <!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Project Manager Selection</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background-color: #f9f9f9;
            margin: 20px;
        }
        .container {
            max-width: 800px;
            margin: auto;
            background: #ffffff;
            padding: 20px;
            border-radius: 10px;
            box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
        }
        h1 {
            text-align: center;
            color: #333;
        }
        table {
            width: 100%;
            border-collapse: collapse;
            margin-top: 20px;
        }
        table, th, td {
            border: 1px solid #ddd;
        }
        th, td {
            padding: 10px;
            text-align: center;
        }
        th {
            background-color: #f4f4f4;
        }
        .btn {
            background-color: #4CAF50;
            color: white;
            padding: 10px 20px;
            border: none;
            border-radius: 5px;
            cursor: pointer;
        }
        .btn:hover {
            background-color: #45a049;
        }
        .project-id {
            margin-top: 20px;
            display: flex;
            align-items: center;
            gap: 10px;
        }
        .project-id input {
            flex: 1;
            padding: 10px;
            border: 1px solid #ddd;
            border-radius: 5px;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>Project Manager Selection</h1>

        <div class="project-id">
            <label for="project-id">Project ID:</label>
            <input type="text" id="project-id" placeholder="Enter Project ID">
        </div>

        <table>
            <thead>
                <tr>
                    <th>Role</th>
                    <th>Employee Name</th>
                    <th>Leadership</th>
                    <th>Communication</th>
                    <th>Programming</th>
                    <th>Problem Solving</th>
                    <th>Creativity</th>
                    <th>Attention to Detail</th>
                    <th>Total Score</th>
                    <th>Select</th>
                </tr>
            </thead>
            <tbody>
                <tr>
                    <td>Team Leader</td>
                    <td>John Doe</td>
                    <td>40</td>
                    <td>45</td>
                    <td>-</td>
                    <td>-</td>
                    <td>-</td>
                    <td>-</td>
                    <td class="total-score">0</td>
                    <td><button class="btn" onclick="assignProject('John Doe')">Select</button></td>
                </tr>
                <tr>
                    <td>Developer</td>
                    <td>Jane Smith</td>
                    <td>-</td>
                    <td>-</td>
                    <td>50</td>
                    <td>40</td>
                    <td>-</td>
                    <td>-</td>
                    <td class="total-score">0</td>
                    <td><button class="btn" onclick="assignProject('Jane Smith')">Select</button></td>
                </tr>
                <tr>
                    <td>Designer</td>
                    <td>Michael Brown</td>
                    <td>-</td>
                    <td>-</td>
                    <td>-</td>
                    <td>-</td>
                    <td>50</td>
                    <td>38</td>
                    <td class="total-score">0</td>
                    <td><button class="btn" onclick="assignProject('Michael Brown')">Select</button></td>
                </tr>
            </tbody>
        </table>

        <button class="btn" style="margin-top: 20px; width: 100%;" onclick="finalizeSelection()">Finalize Selection</button>
    </div>

    <script>
        function calculateTotalScores() {
            const rows = document.querySelectorAll("tbody tr");

            rows.forEach(row => {
                const cells = row.querySelectorAll("td");
                let totalScore = 0;

                for (let i = 2; i <= 7; i++) { // Columns with skill values
                    const value = cells[i].innerText.trim();
                    totalScore += value === "-" ? 0 : parseInt(value, 10);
                }

                // Update the Total Score column
                const totalScoreCell = row.querySelector(".total-score");
                totalScoreCell.innerText = totalScore;
            });
        }

        function assignProject(employeeName) {
            const projectId = document.getElementById('project-id').value;
            if (!projectId) {
                alert('Please enter a Project ID before selecting an employee.');
                return;
            }
            alert(`Project ID ${projectId} has been assigned to ${employeeName}.`);
            // Here, you can add code to send this data to the server for database updates.
        }

        function finalizeSelection() {
            alert('Selection process finalized.');
            // Additional logic to finalize the process can be added here.
        }

        // Calculate scores when the page loads
        window.onload = calculateTotalScores;
    </script>
</body>
</html>

</asp:Content>
