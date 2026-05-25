-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: 06 يونيو 2024 الساعة 16:33
-- إصدار الخادم: 10.4.32-MariaDB
-- PHP Version: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `aokcompany`
--

-- --------------------------------------------------------

--
-- بنية الجدول `account`
--

CREATE TABLE `account` (
  `ID` int(3) NOT NULL,
  `username` varchar(100) NOT NULL,
  `password` varchar(100) NOT NULL,
  `email` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- إرجاع أو استيراد بيانات الجدول `account`
--

INSERT INTO `account` (`ID`, `username`, `password`, `email`) VALUES
(1, 'omar', 'ro515', 'mo5rb600@gmail.com'),
(3, 'omar', 'ro515', 'admin@example.com');

-- --------------------------------------------------------

--
-- بنية الجدول `products`
--

CREATE TABLE `products` (
  `id` int(11) NOT NULL,
  `name` varchar(100) NOT NULL,
  `descripe` varchar(500) NOT NULL,
  `price` varchar(100) NOT NULL,
  `image` varchar(100) NOT NULL,
  `type` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- إرجاع أو استيراد بيانات الجدول `products`
--

INSERT INTO `products` (`id`, `name`, `descripe`, `price`, `image`, `type`) VALUES
(38, 'ali', 'alzoubi', '500', 'picure/14.jpeg', 'fer'),
(42, 'omar', 'alzoubi', '12500', 'picure/0.jpg', 'Mer'),
(43, 'omar 2', 'alzoubi', '125000', 'picure/4.1.jpg', 'fer');

-- --------------------------------------------------------

--
-- بنية الجدول `rate`
--

CREATE TABLE `rate` (
  `rateimg` varchar(200) NOT NULL,
  `personimg` varchar(200) NOT NULL,
  `txt` varchar(200) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- إرجاع أو استيراد بيانات الجدول `rate`
--

INSERT INTO `rate` (`rateimg`, `personimg`, `txt`) VALUES
('img/5 stars.jpg', 'img/boy 1.png', 'gooood'),
('img/5 stars.jpg', 'img/girl 1.jpg', 'llll'),
('img/5 stars.jpg', 'img/girl 1.jpg', 'llll'),
('img/5 stars.jpg', 'img/boy 1.png', 'lll'),
('img/4 stars.jpg', 'img/boy 1.png', 'lll');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `account`
--
ALTER TABLE `account`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `products`
--
ALTER TABLE `products`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `account`
--
ALTER TABLE `account`
  MODIFY `ID` int(3) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT for table `products`
--
ALTER TABLE `products`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=44;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
