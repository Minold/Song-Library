package app;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.layout.BorderPane;
import javafx.stage.Stage;
import view.ListController;

public class SongLib extends Application {
	@Override
	public void start(Stage primaryStage) throws Exception {
		FXMLLoader llr = new FXMLLoader();   
	      llr.setLocation(
	         getClass().getResource("/view/SongList.fxml"));
	      BorderPane root = (BorderPane)llr.load();
	      ListController listController = 
	         llr.getController();
	      listController.start(primaryStage);

	      Scene scene = new Scene(root, 400, 400);
	      primaryStage.setTitle("Song Library - by Minyoung Chung");
	      primaryStage.setScene(scene);
	      primaryStage.setResizable(true);
	      primaryStage.show(); 
	}
	public static void main(String[] args) {
		launch(args);
	}
}
