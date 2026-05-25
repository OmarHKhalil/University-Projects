# GameHub

A web-based gaming platform built with **ASP.NET Web Forms**. GameHub brings together players, developers, and publishers in one place to browse games, explore news, join the community, and manage platform data through an admin workflow.

## Overview

GameHub provides a Steam-inspired storefront experience on the public side, with login, role-based access, and SQL Server–backed pages for managing employees, projects, and requests on the administrative side.

## Features

- **Home** — Hero section, featured games, and login/logout controls
- **Store** — Browse games and gaming news
- **Community** — Community hub and interaction areas
- **About & Support** — Platform information and help content
- **Search** — Client-side search routing to game detail pages
- **Authentication** — User login with role-based redirects (`log in.aspx`)
- **Project management** — Add, view, edit, and delete project records
- **Request workflow** — Submit requests, review them in a grid, accept/reject (`manage.aspx`)
- **Database views** — GridView-based data display (`gridviewproject.aspx`, `dbproject1.aspx`, `dbproject2.aspx`)

## Tech Stack

| Layer | Technology |
|-------|------------|
| Framework | ASP.NET Web Forms (.NET Framework 4.5) |
| Language | C# |
| Database | SQL Server LocalDB (`App_Data`) |
| UI | HTML, CSS (`cs/StyleSheet1.css`), jQuery 3.6.1 |
| Server | IIS Express (Visual Studio) |

## Prerequisites

- [Visual Studio](https://visualstudio.microsoft.com/) 2019 or later (with **ASP.NET and web development** workload)
- **.NET Framework 4.5** (or newer targeting pack)
- **SQL Server LocalDB** (included with Visual Studio)

## Getting Started

### 1. Clone the repository

```bash
# Clone the entire repository
git clone https://github.com/OmarHKhalil/University-Projects.git

# Navigate into the Web Projects Project directory
cd Web Projects/GameHub
```

### 2. Open the solution

Open `ppppppppppppppppppp.sln` in Visual Studio.

### 3. Restore NuGet packages

In Visual Studio: **Tools → NuGet Package Manager → Restore NuGet Packages**

Or from the solution folder:

```powershell
nuget restore pppppppppppppppppppp.sln
```

### 4. Run the application

1. Set the web project as the startup project (if needed).
2. Press **F5** or click **IIS Express**.
3. The site opens at `https://localhost:44324/` (port may vary in your `*.csproj.user` file).

Default entry pages include `home.aspx` and pages linked from `Site1.Master`.

## Database

Connection strings are defined in `Web.config`:

```xml
Data Source=(LocalDB)\MSSQLLocalDB;
AttachDbFilename=|DataDirectory|\Database1.mdf;
Integrated Security=True
```

Database files live under `App_Data/`:

- `Database1.mdf` — primary database
- `Database2.mdf` — secondary database

LocalDB attaches these files automatically at runtime. If you move the project, keep `App_Data` with the `.mdf` files or update the connection string.

## Project Structure

```
├── App_Data/              # SQL Server LocalDB files
├── cs/                    # Stylesheets
├── image/                 # Static images
├── Site1.Master           # Main layout (public pages)
├── Site2.Master           # Alternate layout
├── home.aspx              # Landing page
├── store.aspx             # Store
├── community.aspx         # Community
├── about.aspx             # About
├── support.aspx           # Support
├── log in.aspx            # Login
├── manage.aspx            # Request approval
├── addproject.aspx        # Add project
├── addrequest.aspx        # Add request
├── gridviewproject.aspx   # Projects grid
├── editinfo.aspx          # Edit records
├── deletinfo.aspx         # Delete records
├── search and download.aspx
├── dbproject1.aspx        # Game/detail page 1
├── dbproject2.aspx        # Game/detail page 2
├── Web.config             # App & connection settings
└── pppppppppppppppppppp.sln
```

## Main Pages

| Page | Purpose |
|------|---------|
| `home.aspx` | Home and featured games |
| `store.aspx` | Game store and news |
| `community.aspx` | Community section |
| `about.aspx` | About the platform |
| `support.aspx` | Support |
| `log in.aspx` | Sign in |
| `manage.aspx` | Manage and approve requests |
| `addrequest.aspx` | Create a new request |
| `addproject.aspx` | Add a project |
| `gridviewproject.aspx` | List projects |
| `editinfo.aspx` / `deletinfo.aspx` | Update or remove data |