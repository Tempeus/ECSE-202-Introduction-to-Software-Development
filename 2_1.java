import java.awt.Color;
import acm.graphics.GLine;
import acm.program.GraphicsProgram;
import acm.util.RandomGenerator;

public class bSim extends GraphicsProgram {
	//required parameters for the program
	private static final int WIDTH = 1200;
	private static final int HEIGHT = 600;
	private static final int OFFSET = 200;
	private static final int NUMBALLS = 100;  // change to 100
	private static final double MINSIZE = 3;
	private static final double MAXSIZE = 20;
	private static final double XMIN = 10;
	private static final double XMAX = 50;
	private static final double YMIN = 50;
	private static final double YMAX = 100;
	private static final double EMIN = 0.1;
	private static final double EMAX = 0.3;
	private static final double VMIN = 0.5;
	private static final double VMAX = 3.0;
	
	RandomGenerator rgen = new RandomGenerator();
		
	public void run() {
		//set up display, create and start multiple instances of gball
		this.resize(WIDTH, HEIGHT + OFFSET);
		GLine ground = new GLine(0,HEIGHT,WIDTH,HEIGHT);
		add(ground);
		
		
		for(int i = 0; i < NUMBALLS; i++) {
			double iX = rgen.nextDouble(XMIN,XMAX);
			double iY = rgen.nextDouble(YMIN,YMAX);
			double iSize = rgen.nextDouble(MINSIZE,MAXSIZE);
			Color iColor = rgen.nextColor();
			double iE = rgen.nextDouble(EMIN,EMAX);
			double iV = rgen.nextDouble(VMIN,VMAX);
			
			gBall iball = new gBall(iX *10,iY * 10,iSize ,iColor ,iE ,iV);
			add(iball.myBall);
			iball.start();
		}
	}
}
