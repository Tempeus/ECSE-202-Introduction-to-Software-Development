import acm.graphics.GLine;
import acm.program.GraphicsProgram;

public class bSim extends GraphicsProgram {
	//required parameters for the program
	private static final int WIDTH = 1200;
	private static final int HEIGHT = 600;
	private static final int OFFSET = 200;
	private static final int NUMBALLS = 100;
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
	
	public void run() {
		//set up display, create and start multiple instances of gball
		this.resize(WIDTH,800);
		GLine ground = new GLine(0,HEIGHT,WIDTH,HEIGHT);
		add(ground);
	}
}
