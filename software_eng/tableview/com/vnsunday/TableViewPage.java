package com.vnsunday;

import java.awt.FlowLayout;

import javax.swing.*;

public class TableViewPage extends JFrame {
	
	JButton b1;
	JButton b2;
	
	public TableViewPage() {
		b1 = new JButton("Login");
		b2 = new JButton("Cancel");
		
		setLayout(new FlowLayout());
		add(b1);
		add(b2);
	}
}
