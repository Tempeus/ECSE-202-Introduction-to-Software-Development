import java.awt.Color;

import acm.graphics.*;
import acm.program.*;

public class ballPROP extends GraphicsProgram{
	public void run() {
		
		/*
		 * The properties of the background & ball
		 */
		this.resize(1000,800); // properties of the canvas
		GOval ball = new GOval(200,100,100,100); // the location and size of the ball
		ball.setFilled(true); // physical properties of the ball
		ball.setColor(Color.BLUE);
		add(ball);
		
		/*
		 * The falling mechanism of the ball
		 */
		double y = 100;
		double t = 0.001;

		while (y <= 700) {
			ball.setLocation(200.0,y);
			y += (4.9)*(t*t);
			t += 0.001;
			pause(1);
		/*
		 * The bounce mechanics of the ball
		 */
		
		}
	}
}


//test
//double t = 0.001;
//for (double y = 100; y < 700; y += (1/2)*(9.8)*(t*t)) {
	//ball.setLocation(200.0,y);
	//t += 0.001;
	//pause(20);
