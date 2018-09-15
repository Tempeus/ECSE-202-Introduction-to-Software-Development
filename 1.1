package temp; 

import java.awt.Color;
import java.lang.Math;
import acm.graphics.*;
import acm.program.*;

public class bounce extends GraphicsProgram {
	private static final double G = 9.8;
	public void run() {
		//display window
		this.resize(1000,800); // properties of the canvas
		
		//identifying important variables
		double h_max = readDouble("Enter the initial height of the ball [0,700]: "); // implement anti error conditions
		double h = h_max;
		double e = readDouble("Enter the energy loss entered as a number [0,1]: ");
		double vt = 0;
		boolean dirUp = false; // direction down
		double t_eq = 0.001;
		double t_del = 0;
		double t_tot = 0;
		double vi = 0;
		double vf = (vi + G * t_eq);
		boolean loop = true;
		
		//ball
		GOval ball = new GOval(200,100,50,50); // the location and size of the ball
		ball.setFilled(true); // physical properties of the ball
		ball.setColor(Color.BLUE);
		add(ball);
		
		//line	
		GLine ground = new GLine(0,800,1000,800); // this value will be affected if changing the size of canvas
		add(ground);
		
		//movement of ball (will be affected if changing the size of canvas)
		double y = 800 - h; // y <= 750 unused
		
		while (loop) {
			if (!dirUp) {
				h = h - 0.5*G*(t_eq*t_eq);
				
				if (h <= 750) { // ground impact
					dirUp = true;
					vt = Math.sqrt(2*e*G*h_max);
					t_tot += t_eq;
					t_eq = 0;
					pause(1);
				}
				else {
					t_eq += 0.001;
					pause(1);
				}
			}
			if (dirUp) {
				h = vt - 0.5*G*(t_eq*t_eq);
				
			}
		}
		
		
		
		
		/*if (!directionUP) {
			h = y + (0.5)*(G)*(t*t);
			if (h <= 0) { // ground impact
				vt = Math.sqrt(2*e*G*y); //setting terminal velocity and energy loss
				y = h; 
				directionUP = true;
				totalTime += t;
				t = 0; // resetting time for upward arc
				ball.setLocation(200.0,h);
				t += 0.001;
				pause(1);
			}
			else {
				ball.setLocation(200.0,h);
				t += 0.001;
				pause(1);
			}
		}
		*/
		
		/*while (y <= 750) {
			ball.setLocation(200.0,y);
			y += (G/2)*(t*t);
			t += 0.001;
			pause(1); */
		
	}
}
