import java.awt.Color;
import acm.graphics.*;
import acm.program.*;

public class Bounce extends GraphicsProgram {
	private static final double G = 9.8;
	public void run() {
		
		//display window
		this.resize(800,800); // properties of the canvas
		
		//identifying important variables
		double hInput = readDouble("Enter the initial height of the ball [0,700]: "); // implement anti error conditions
		double h_max = 750 - hInput; // since the origin of the canvas is top right, we must subtract by the floor
		double h = h_max;
		double energyLoss = readDouble("Enter the energy loss entered as a number [0,1]: ");
		double e = 1 - energyLoss;
		boolean dirUp = false; // direction down
		double t_eq = 0.001;
		double v = 0;
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
				v = (G * t_eq); // changes the velocity according to time and gravity
				h = v * t_eq; // must change this variable universally
				
				if (h >= 700) { // ground impact
					println("GROUND"); // indication that this if statement is triggered
					dirUp = true; // changes the direction of the ball
					h_max = h; //
					v = e * v; // must change this variable universally 
					t_eq = 0; // reset the time to 0
				}
				
				ball.setLocation(200.0,h);
				t_eq += 0.01; 
				println(h); // print out the position of the ball
				pause(1);
			}
			
			if (dirUp) {
				h = v * t_eq; // for some reason the value here is not changed from the if statement above
				v =(-G * t_eq);//this shouldn't be negative
				ball.setLocation(200.0,h);
				println(h);
				t_eq += 0.01;
				pause(1);
				
				if (h > h_max) {
					h_max = h;
				}
				
				if (h == 0) {
					println("hi");
					dirUp = false;
					t_eq = 0;
				}
				
			}
		}
	}
}
