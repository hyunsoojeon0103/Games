import javafx.stage.Screen;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.application.Application;


public class main extends Application 
{
	private final double TILEPANELWIDTH = Screen.getPrimary().getVisualBounds().getWidth()/2.0;
	private final double TILEPANELHEIGHT = TILEPANELWIDTH;
	private final double RIGHTSIDE = TILEPANELWIDTH/2.0;
	public void start(Stage stage)
	{
		Game_Of_15 gameOf15 = new Game_Of_15(TILEPANELWIDTH,TILEPANELHEIGHT,RIGHTSIDE);
		Scene scene = new Scene(gameOf15,TILEPANELWIDTH+RIGHTSIDE,TILEPANELHEIGHT-10.0);
		stage.setScene(scene);
		stage.setTitle("Prototype");
		stage.setResizable(false);
		stage.show();
	}
	public static void main(String[] args)
	{
		launch(args);
	}
	
}
