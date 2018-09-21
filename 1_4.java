import java.awt.Color;
import acm.graphics.*;
import acm.program.*;

public class Bounce extends GraphicsProgram {
	private static final double G = 9.8;
	public void run() {
		
		//display window
		this.resize(800,800); // properties of the canvas
		
		//identifying important variables
		double h0 = readDouble("Enter the initial height of the ball [0,700]: "); // implement anti error conditions
		double h = 0;
		double e = readDouble("Enter the energy loss entered as a number [0,1]: ");
		double vt = Math.sqrt(2 * G *h0);
		double totalTime = 0;
		double t = 0;
		double initialUpPosition = 0;
		double intervalTime = 0.1;
		double vx = 5;
		double xPos = 0;
		boolean dirUp = false; // direction down
		boolean loop = true;
		
		//ball properties
		GOval ball = new GOval(200,100,50,50); // the location and size of the ball
		ball.setFilled(true); // physical properties of the ball
		ball.setColor(Color.BLUE);
		add(ball);
		
		//line	property
		GLine ground = new GLine(0,750,1000,750); // this value will be affected if changing the size of canvas
		add(ground);
		
		//movement mechanic of the ball (will be affected if changing the size of canvas)
		while (loop) { // generates an infinity loop
			if (!dirUp) { // which the ball is dropping
				h = h0 - 0.5 * G * Math.pow(t, 2);
				if (h <= 0) { // ground impact
					println("GROUND"); // indication that this if statement is triggered
					dirUp = true; // changes the direction of the ball
					t = 0;
					vt = vt * Math.sqrt(1 - e);
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
			xPos = xPos + vx*intervalTime;
			println("Time: " + totalTime + " X: " + xPos + " Y: " + h);
			
			t+= intervalTime;
			totalTime += intervalTime;
			pause(intervalTime*1000);
			
			add(new GOval(xPos+30,570-h,1,1));
			ball.setLocation(xPos, 540-h);
		}
	}
}
