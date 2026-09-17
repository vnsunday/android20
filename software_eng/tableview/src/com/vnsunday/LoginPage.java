package com.vnsunday;
import java.util.concurrent.TimeUnit;

import javax.swing.*;

/**
 * LoginPage
 */
public class LoginPage {

    public static void main(String[] args) throws Exception {
        JFrame frame = new JFrame("Login");
        JLabel label = new JLabel("Enter credential");
        
        frame.add(label);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(600, 150);
        frame.setVisible(true);
    
        TimeUnit.SECONDS.sleep(2);
        label.setText("Username and Password");
    }
}