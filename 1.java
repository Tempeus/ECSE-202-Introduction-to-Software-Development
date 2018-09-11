import java.awt.Color;

import acm.graphics.*;
import acm.program.*;

public class Bounce extends GraphicsProgram {
	private static final double G = 9.8;
	public void run() {
		//display window
		this.resize(1000,800); // properties of the canvas
		
		//identifying important variables
		double height = readDouble("Enter the initial height of the ball [0,700]: "); // implement anti error conditions
		double energyLoss = readDouble("Enter the energy loss entered as a number [0,1]: ");
		double vt = Math.sqrt(2*G*height);
		boolean dirrectionUP = false; // direction down
		double time = 0; 
		
		//ball
		GOval ball = new GOval(200,100,100,100); // the location and size of the ball
		ball.setFilled(true); // physical properties of the ball
		ball.setColor(Color.BLUE);
		add(ball);
		
		//line
		GLine ground = new GLine(0,750,1000,750); // this value will be affected if changing the size of canvas
		add(ground);
		
		//movement of ball (will be affected if changing the size of canvas)
		double y = 100;
		double t = 0.001;

		while (y <= 650) {
			ball.setLocation(200.0,y);
			y += (4.9)*(t*t);
			t += 0.001;
			pause(1);
		}
	}
}
