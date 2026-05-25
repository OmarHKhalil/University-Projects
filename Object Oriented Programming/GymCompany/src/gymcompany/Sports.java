/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package gymcompany;

import java.util.ArrayList;

/**
 *
 * @author aa
 */
public class Sports {
  private static int counter = 0;
    private int sport_id;
    private String name;
    private int roomNum;
    private int num_of_place;
    private String timing;
    private String coachName;
    private double subPrice;

    public Sports(String name, int roomNum, int num_of_place, String timing, String coachName, double subPrice) {
        counter++;
        sport_id=counter;
        this.name = name;
        this.roomNum = roomNum;
        this.num_of_place = num_of_place;
        this.timing = timing;
        this.coachName = coachName;
        this.subPrice = subPrice;
    }

    Sports() {
 
    }

    public int getSport_id() {
        return sport_id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getRoomNum() {
        return roomNum;
    }

    public void setRoomNum(int roomNum) {
        if (roomNum <= 0) {
            this.roomNum = Math.abs(roomNum);
        } else {
            this.roomNum = roomNum;
        }
    }

    public int getNum_of_place() {
        return num_of_place;
    }

    public void setNum_of_place(int num_of_place) {
        this.num_of_place = num_of_place;
    }

    public String getTiming() {
        return timing;
    }

    public void setTiming(String timing) {
        this.timing = timing;
    }

    public String getCoachName() {
        return coachName;
    }

    public void setCoachName(String coachName) {
        this.coachName = coachName;
    }

    public double getSubPrice() {
        return subPrice;
    }

    public void setSubPrice(double subPrice) {
        this.subPrice = subPrice;
    }
    public static Sports CreateSport(String name, int roomNum, int num_of_place, String timing, String coachName, double subPrice) {
        Sports s = new Sports(name, roomNum, num_of_place, timing, coachName, subPrice);
        return s;
    }
    public void sportavalible(ArrayList<Sports> sport) {
        for (Sports sp : sport) {
            System.out.println(sp);
        }
    }
    public int exist() {
        if (num_of_place > 0) {
            return 1;
        } else {
            return 0;
        }
    }
    public void min() {
        num_of_place = num_of_place - 1;
    }
     public String toString() {
        return String.format("Sports[Sport Name: %s -- total place: %d -- price %s$]", name, num_of_place, subPrice);
    }
}
