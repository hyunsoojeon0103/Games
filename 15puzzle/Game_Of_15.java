import javafx.scene.layout.GridPane;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.animation.Timeline;
import javafx.animation.Animation;
import javafx.animation.KeyFrame;
import javafx.util.Duration;
import javafx.scene.layout.StackPane;
import java.util.Random;
import javafx.geometry.Pos;
public class Game_Of_15 extends BorderPane
{
	private GridPane tilePanel = new GridPane();
	private VBox rightPanel = new VBox();
	private final int SIZE =10;
	private final int X=SIZE;
	private final int Y=SIZE;
	private final int tileCtr = X*Y;
	private double tileWidth;
	private double tileHeight;
	private double rightPanelWidth;
	private double RIGHT_ELEMENTS_WIDTH;
	private Timeline time = new Timeline();
	private int minutesTaken =0;
	private int secondsTaken =0;
	private int millisTaken =0;
	private Label clock = new Label("00:00:000");
	private TextField nameBox = new TextField("Name");
	private tiles[] tileArray = new tiles[tileCtr];
	private Button start = new Button("Start");
	private Button stop = new Button("Stop");
	private Button reset = new Button("Reset");
	private Button shuffle = new Button("Shuffle");
	private Button sort = new Button("Sort");
	boolean hasStarted = false;
	boolean hasReset = false;

	public Game_Of_15(final double tilePanelWidth,final double tilePanelHeight,final double rightSideWidth)
	{
		setTileWidth(tilePanelWidth);
		setTileHeight(tilePanelHeight);
		setRightPanelWidth(rightSideWidth);
		setRightElementsWidth();
		setTiles();
		setRightPanel();
		tilePanel.setDisable(true);
		setLeft(tilePanel);
		setCenter(rightPanel);
	}
	public void setTiles()
	{
		int value = 0;
		for(int y=0; y<Y; ++y )
			for(int x=0; x<X; ++x)
			{
				tileArray[value] = new tiles(value,x,y);
				tilePanel.add(tileArray[value],
						tileArray[value].getX(),
						tileArray[value].getY());
				++value;
			}
	}
	public void setRightPanel()
	{
		rightPanel.setStyle("-fx-background-color:#FFF380;");
		rightPanel.setPrefWidth(getRightPanelWidth());
		rightPanel.setSpacing(RIGHT_ELEMENTS_WIDTH/4);
		clock.setFont(Font.font(RIGHT_ELEMENTS_WIDTH/4));
		nameBox.setMaxWidth(RIGHT_ELEMENTS_WIDTH);
		start.setPrefWidth(RIGHT_ELEMENTS_WIDTH);
		start.setOnMouseClicked(e->startGame());
		stop.setPrefWidth(RIGHT_ELEMENTS_WIDTH);
		stop.setOnMouseClicked(e->stopTimer());
		reset.setPrefWidth(RIGHT_ELEMENTS_WIDTH);
		reset.setOnMouseClicked(e->resetTiles());
		shuffle.setPrefWidth(RIGHT_ELEMENTS_WIDTH);
		shuffle.setOnMouseClicked(e->shuffleTiles());
		sort.setPrefWidth(RIGHT_ELEMENTS_WIDTH);
		sort.setOnMouseClicked(e->sortTiles());
		rightPanel.getChildren().addAll(clock,nameBox,start,stop,reset,shuffle,sort);
		rightPanel.setAlignment(Pos.CENTER);
	}
	public void startGame()
	{
		if(!hasStarted)
		{
			tilePanel.setDisable(false);
			shuffleTiles();
			startTimer();
			hasStarted = true;
		}
		else
		{
			if(hasReset)
			{
				shuffleTiles();
				hasReset = false;
			}
			time.play();
			tilePanel.setDisable(false);
		}
	}
	public void startTimer()
	{
		time.setCycleCount(Timeline.INDEFINITE);
		KeyFrame frame = new KeyFrame(Duration.millis(1), e->{
			++millisTaken;
			if(millisTaken == 1000)
			{
				++secondsTaken;
				if(secondsTaken==60)
				{
					++minutesTaken;
					secondsTaken = 0;
				}
				millisTaken = 0;
			}
			clock.setText(String.format("%02d",minutesTaken) + ':'
					+ String.format("%02d", secondsTaken) + ':'
					+ String.format("%03d", millisTaken));
		});
		time.getKeyFrames().add(frame);
		time.playFromStart();
	}
	public void stopTimer()
	{
		time.pause();
		tilePanel.setDisable(true);
	}
	public void sortTiles()
	{
		tilePanel.getChildren().removeAll(tileArray);
		setTiles();
	}
	public void resetTiles()
	{
		if(time.getStatus() == Animation.Status.RUNNING)
			stopTimer();
		sortTiles();
		minutesTaken = 0;
		secondsTaken = 0;
		millisTaken = 0;
		clock.setText("00:00:000");
		hasReset = true;
	}
	public void shuffleTiles()
	{
		Random rand = new Random();
		for(int i=0; i<tileCtr; ++i)
			tileArray[i].swap(tileArray[rand.nextInt(tileCtr)]);
	}
	public void setTileWidth(final double tilePanelWidth)
	{
		tileWidth = tilePanelWidth/ X;
	}
	public double getTileWidth()
	{
		return tileWidth;
	}
	public void setTileHeight(final double tilePanelHeight)
	{
		tileHeight = tilePanelHeight / (double)Y;
	}
	public double getTileHeight()
	{
		return tileHeight;
	}
	public void setRightPanelWidth(final double rightSideWidth)
	{
		rightPanelWidth = rightSideWidth/2.0;
	}
	public void setRightElementsWidth()
	{
		RIGHT_ELEMENTS_WIDTH = rightPanelWidth;
	}
	public double getRightPanelWidth()
	{
		return rightPanelWidth;
	}
	class tiles extends StackPane
	{
		private int value;
		private int x;
		private int y;
		public tiles()
		{
			this(0,0,0);
		}
		public tiles(final int value,final int x, final int y)
		{
			set(value,x,y);
			if(value<tileCtr-1)
			{	
				Button tile = new Button(String.format("%d", getValue()));
				tile.setPrefWidth(getTileWidth());
				tile.setPrefHeight(getTileHeight());
				tile.setFont(Font.font(getTileWidth()/4));
				tile.setTextFill(Color.WHITE);
				tile.setOnMouseEntered(e->{
					if(this.canItMove())
						tile.setStyle("-fx-background-color:#48a4ff; -fx-border-color:white;");
					else
						tile.setStyle("-fx-background-color:#ff6347; -fx-border-color:white;");
						
				});
				if(getValue()%2 == 0)
				{
					tile.setStyle("-fx-background-color:#4E9258; -fx-border-color:white;");
					tile.setOnMouseExited(e->tile.setStyle("-fx-background-color:#4E9258;-fx-border-color:white;"));
				}
				else
				{
					tile.setStyle("-fx-background-color:#FBB917; -fx-border-color:white;");
					tile.setOnMouseExited(e->tile.setStyle("-fx-background-color:#FBB917;-fx-border-color:white;"));
				}
				getChildren().add(tile);
				tile.setOnMouseClicked(e->{if(canItMove())swap(tileArray[tileCtr-1]);});
			}
			else
			{
				Button tile = new Button();
				tile.setStyle("-fx-background-color:white;");
				tile.setPrefWidth(getTileWidth());
				tile.setPrefHeight(getTileHeight());
				getChildren().add(tile);
			}
		}
		public void set(final int value,final int x, final int y)
		{
			this.value= value + 1;
			this.x=x;
			this.y=y;
		}
		public void swap(tiles target)
		{
			if(this != target)
			{
				tilePanel.getChildren().remove(target);
				tilePanel.getChildren().remove(this);
				tilePanel.add(target, getX(), getY());
				tilePanel.add(this, target.getX(), target.getY());
				int tempX = getX();
				int tempY = getY();
				int tempValue = getValue();
				this.x = target.getX();
				this.y = target.getY();
				this.value = target.getValue();
				target.setX(tempX);
				target.setY(tempY);
				target.setValue(tempValue);
			}
		}
		public boolean canItMove()
		{
			return ((Math.abs((value)-tileArray[tileCtr-1].getValue()) == 1)&&
					y==tileArray[tileCtr-1].getY()) ||
					(Math.abs(value-tileArray[tileCtr-1].getValue())==SIZE);
		}
		public void setX(final int x)
		{
			this.x = x;
		}
		public void setY(final int y)
		{
			this.y= y;
		}
		public void setValue(final int value)
		{
			this.value= value;
		}
		public int getValue()
		{
			return value;
		}
		public int getX()
		{
			return x;
		}
		public int getY()
		{
			return y;
		}
	}
}
