import acm.graphics.GOval;
import java.awt.Color;

/**
 * This class will provide an instance of a ball falling 
 * while under the influence of gravity. Because of the 
 * Thread extension, each instance will run concurrently,
 * with animations on the screen as a side effect.
 * 
 * @author Kevin Li
 *
 */

public class gBall extends Thread {
	
	public GOval myBall;
	
	//constant units
	private static final double G = 9.8;
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
		
		//properties of ball instance
		myBall = new GOval(this.Xi, this.Yi, this.bSize * 2, this.bSize * 2);
		myBall.setFilled(true);
		myBall.setFillColor(this.bColor);
		
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
		double vt = Math.sqrt(2*G*this.Yi);
		double t = 0;
		double initialUpPosition = 0;
		double xPos = 0;
		boolean dirUp = false; //direction down
		
		while (true) {
			if (!dirUp) {
				h = this.Yi - 0.5 * G *Math.pow(t, 2);
				if (h <= 0) {
					this.Yi = h;
					initialUpPosition = 0; // to ensure the ball touches the ground and doesn't go through it
					h = 0; // to ensure the ball touches the ground and doesn't go through.
					t = 0; // reset the time to 0
					vt = vt * Math.sqrt(1 - this.bLoss); // applying energy loss to the terminal velocity.
					dirUp = true; // Chances the direction of the ball
				}
			}
			
			else {
				h = initialUpPosition + vt * t - 0.5 * G * Math.pow(t,2);
				if (h > this.Yi) {
					this.Yi = h;
				}
				
				else {
					dirUp = false; // when the ball starts to drop
					t = 0; // reset the time to 0
				}
			}
			xPos = xPos + this.bVel *intervalTime;
			t += intervalTime; // increasing the time by the interval
			myBall.setLocation(xPos ,600 - (this.bSize * 2) - h);
			
			try {
				Thread.sleep(50);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
}
