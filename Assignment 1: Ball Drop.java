import acm.graphics.GLine;
import acm.graphics.GOval;
import acm.program.GraphicsProgram;

import java.awt.Color;
import java.awt.color.*;

/**
 * This class will provide an instance of a ball falling 
 * while under the influence of gravity. Because of the 
 * Thread extension, each instance will run concurrently,
 * with animations on the screen as a side effect.
 * 
 * @author kli69
 *
 */

public class gBall extends Thread {
	
	
	
	public GOval myBall;
	
	//constant units
	private static final double G = 9.8;
	private static final double TimeOut = 30;
	private static final double intervalTime = 0.1;
	
	//initialization of parameters
	double Xi;
	double Yi;
	double bSize;
	Color bColor;
	double bLoss;
	double bVel;
	
	/**
	 * Specified parameters for the simulation
	 * 
	 * @param Xi		double		The initial X position of the center of the ball
	 * 
	 * @param Yi		double		The initial Y position of the center of the ball
	 * 
	 * @param bSize		double		The radius of the ball in simulation units
	 * 
	 * @param bColor	Color		The initial color of the ball 
	 * 
	 * @param bLoss		double		Fraction [0,1] of the energy loss on each bounce
	 * 
	 * @param bvel		double		X velocity of ball
	 */
	
	public gBall(double Xi, double Yi,double bSize, Color bColor, double bLoss, double bVel) {
		//simulation parameters
		this.Xi = Xi;
		this.Yi = Yi;
		this.bSize = bSize;
		this.bColor = bColor;
		this.bLoss = bLoss;
		this.bVel = bVel;
				
	}
	
	/**
	 * The following run method implements the simulation that I created from the previous assignment.
	 * Once the start method is called on the gBall instance, the code in the run method is executed
	 * concurrently with the main program.
	 * @param void
	 * @return void
	 */
	
	public void run() {
		
		//variables used in the program
		double h = 0;
		double vt = Math.sqrt(2*G*Yi);
		double totalTime = 0;
		double t = 0;
		double initialUpPosition = 0;
		double xPos = 0;
		boolean dirUp = false; //direction down
		
	
		//properties of ball instance
		myBall = new GOval(this.Xi, this.Yi, this.bSize, this.bSize);
		myBall.setFilled(true);
		myBall.setFillColor(this.bColor);
		
		while (totalTime <= TimeOut) {
			if (!dirUp) {
				h = Yi - 0.5 * G *Math.pow(t, 2);
				if (h <= 0) {
					Yi = h;
					initialUpPosition = 0; // to ensure the ball touches the ground and doesn't go through it
					h = 0; // to ensure the ball touches the ground and doesn't go through.
					dirUp = true; // Chances the direction of the ball
					t = 0; // reset the time to 0
					vt = vt * Math.sqrt(1 - bLoss); // applying energy loss to the terminal velocity.
				}
			}
			
			else {
				h = initialUpPosition + vt * t - 0.5 * G * Math.pow(t,2);
				if (h > Yi) {
					Yi = h;
				}
				
				else {
					dirUp = false; // when the ball starts to drop
					t = 0; // reset the time to 0
				}
			}
			xPos = xPos + bVel *intervalTime;
			System.out.println("Time: " + totalTime + " X: " + xPos + " Y: " + h); // printing the results of the ball
			
			t += intervalTime; // increasing the time by the interval
			totalTime += intervalTime; // increasing the total time elapsed

		}
	}
}


// [] IMPLEMENT THREAD
