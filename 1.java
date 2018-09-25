/* Name: Kevin Li
 * Student ID: 260862327
 * Date: 2018.09.25
 */

import java.awt.Color;
import acm.graphics.*;
import acm.program.*;


public class Li_260862327_A1 extends GraphicsProgram {
	private static final double G = 9.8;
	private static final double TimeOut = 30;
	private static final double intervalTime = 0.1;
	
	public void run() {

		// display window
		this.resize(800, 800); // properties of the canvas

		// identifying important variables
		double h0 = 10 * readDouble("Enter the initial height of the ball in meters [0,60]: "); // implement anti error conditions
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
		GOval ball = new GOval(200, 100, 60, 60); // the location and size of the ball
		ball.setFilled(true); // physical properties of the ball
		ball.setColor(Color.BLUE);
		add(ball);

		// line property
		GLine ground = new GLine(0, 600, 1000, 600); // this value will be affected if changing the size of canvas
		add(ground);

		// movement mechanic of the ball (will be affected if changing the size of canvas
		while (totalTime <= TimeOut) { // will terminate the animation as soon as the timeout is reached
			if (!dirUp) { // which direction the ball is dropping
				h = h0 - 0.5 * G * Math.pow(t, 2);
				if (h <= 0) { // ground impact
//					println("GROUND"); // test: indicate if this part of the program is executing
					h0 = h;
					initialUpPosition = 0; // to ensure the ball touches the ground and doesn't go through
					h = 0; // to ensure the ball touches the ground and doesn't go through
					dirUp = true; // changes the direction of the ball
					t = 0; // reset the time to 0
					vt = vt * Math.sqrt(1 - e); // applying energy loss to the terminal velocity
				}
			}
			
			else {
				h = initialUpPosition + vt * t - 0.5 * G * Math.pow(t, 2); 
				if (h > h0) {
					h0 = h;
				} 
				
				else {
					dirUp = false; // when the ball starts to drop
					t = 0; // reset the time to 0
				}
			}
			xPos = xPos + vx * intervalTime;
			println("Time: " + totalTime + " X: " + xPos + " Y: " + h); // printing the results of the ball

			t += intervalTime; // increasing the time by the interval
			totalTime += intervalTime * 0.1; // increasing the total time elapsed and multiplying by 0.1 or else time will elapse too fast
			pause(10); // pausing for 10 milliseconds for a smoother drop

			// tracer property
			add(new GOval(xPos + 30, 570 - h, 1, 1)); //ensuring that the tracer is at the middle of the ball
			ball.setLocation(xPos, 540 - h); //ensuring that the tracer is at the middle of the ball
		}
	}
}
