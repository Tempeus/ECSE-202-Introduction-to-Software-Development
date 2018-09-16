import java.awt.Color;
import java.lang.Math;
import acm.graphics.*;
import acm.program.*;

public class Bounce extends GraphicsProgram {
	private static final double G = 9.8;
	public void run() {
		//display window
		this.resize(800,800); // properties of the canvas
		
		//identifying important variables
		double hInput = readDouble("Enter the initial height of the ball [0,700]: "); // implement anti error conditions
		double h_max = 750 - hInput;
		double h = h_max;
		double energyLoss = readDouble("Enter the energy loss entered as a number [0,1]: ");
		double e = 1 - energyLoss;
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
		GLine ground = new GLine(0,750,1000,750); // this value will be affected if changing the size of canvas
		add(ground);
		
		//movement of ball (will be affected if changing the size of canvas)
		
		while (loop) {
			if (!dirUp) {
				h = h_max + 0.5*G*(t_eq*t_eq);
				
				if (h >= 750) { // ground impact
					println("GROUND");
					dirUp = true;
					h_max = h;
					vt = Math.sqrt(2*e*G*h_max);
					t_eq = 0;
				}
				
				ball.setLocation(200.0,h);
				t_eq += 0.01;
				println(h);
				pause(1);

			}
			if (dirUp) {
				h = vt - 0.5*G*(t_eq*t_eq); // Something is happening here
				ball.setLocation(200.0,h);
				println(h);
				t_eq += 0.01;
				pause(1);
				
				if (h > h_max) {
					h_max = h;
					
				}
				//if (h == 0) {
					//dirUp = false;
					//t_eq = 0;
				//}
				
			}
		}
	}
}
