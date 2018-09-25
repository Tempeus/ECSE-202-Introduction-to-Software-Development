/* Name: Kevin Li
 * Student ID: 260862327
 * Date: 2018.09.25
 */

import java.awt.Color;
import acm.graphics.*;
import acm.program.*;


public class Bounce extends GraphicsProgram {
	private static final double G = 9.8;
	private static final double TimeOut = 30;
	private static final double intervalTime = 0.1;
	
	public void run() {

		// display window
		this.resize(800, 800); // properties of the canvas

		// identifying important variables
		double h0 = 10 * readDouble("Enter the initial height of the ball in meters [0,70]: "); // implement anti error conditions
		double h = 0;
		double e = readDouble("Enter the energy loss entered as a number [0,1]: ");
		double vt = Math.sqrt(2 * G * h0);
		double totalTime = 0;
		double t = 0;
		double initialUpPosition = 0;
		double vx = readDouble("Enter the horizontal velocity: ");
		double xPos = 0;
		boolean dirUp = false; // direction down

		// ball properties
		GOval ball = new GOval(200, 100, 50, 50); // the location and size of the ball
		ball.setFilled(true); // physical properties of the ball
		ball.setColor(Color.BLUE);
		add(ball);

		// line property
		GLine ground = new GLine(0, 600, 1000, 600); // this value will be affected if changing the size of canvas
		add(ground);

		// movement mechanic of the ball (will be affected if changing the size of canvas
		while (totalTime <= TimeOut) { // generates an infinity loop
			if (!dirUp) { // which direction the ball is dropping
				h = h0 - 0.5 * G * Math.pow(t, 2);
				if (h <= 0) { // ground impact
//					println("GROUND"); // indication that this if statement is triggered
					h0 = h;
					initialUpPosition = 0;
					h = 0;
					dirUp = true; // changes the direction of the ball
					t = 0;
					vt = vt * Math.sqrt(1 - e);
				}
			}
			
			else {
				h = initialUpPosition + vt * t - 0.5 * G * Math.pow(t, 2); // for some reason the value here is not changed from the if statement above
				if (h > h0) {
					h0 = h;
				} 
				
				else {
					dirUp = false;
					t = 0;
				}
			}
			xPos = xPos + vx * intervalTime;
			println("Time: " + totalTime + " X: " + xPos + " Y: " + h);

			t += intervalTime;
			totalTime += intervalTime * 0.1;
			pause(10);

			// tracer property
			add(new GOval(xPos + 25, 575 - h, 1, 1));
			ball.setLocation(xPos, 550 - h);
		}
	}
}
