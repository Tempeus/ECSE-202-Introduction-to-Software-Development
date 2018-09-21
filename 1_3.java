import java.awt.Color;
import acm.program.*;
import acm.graphics.*;

public class Bounce extends GraphicsProgram {
	public void run() {
		
		//display window
		this.resize(600,800);
		
		double G = 9.8;
		double h0 = readDouble ("h0 = ");
		double l = readDouble ("l = ");
		double vt = Math.sqrt(2*G*h0);
		double totalTime= 0;
		double TIME_OUT = 30;
		double height = 0;
		double time = 0;
		double initialUpPosition = 0;
		double INTERVAL_TIME= 0.1;
		double vx = 5;
		double xPos = 0;
		boolean directionUp = false;
		
		//Ball property
		GOval ball = new GOval(200,100,50,50); // the location and size of the ball
		ball.setFilled(true); // physical properties of the ball
		ball.setColor(Color.BLUE);
		add(ball);
		
		//Ground property
		GLine ground = new GLine(0,600,800,600); // this value will be affected if changing the size of canvas
		add(ground);
		
		
		//Movement algorithm
		while (totalTime < TIME_OUT) {
			if (!directionUp) {
				height = h0 - 0.5 * G * Math.pow(time, 2);
				if (height <= 0) {
					initialUpPosition = height;
					directionUp = true;
					time = 0;
					vt = vt * Math.sqrt(1 - l);
				}
				else {
					height = initialUpPosition + vt * time - 0.5 * G * Math.pow(time,2);
					if (height > h0) {
						h0 = height;
					}
					else {
						directionUp = false;
						time = 0;
					}
				}
				
				
				xPos = xPos + vx*INTERVAL_TIME;
				println("Time: " + totalTime + " X: " + xPos + " Y: " + height);
				
				time += INTERVAL_TIME;
				totalTime += INTERVAL_TIME;
				pause(INTERVAL_TIME*1000);
				
				add(new GOval(xPos+30,570-height,1,1));
				ball.setLocation(xPos, 540-height);
			}
		}
	}
}
