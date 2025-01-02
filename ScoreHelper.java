// scorehelper.java
public class ScoreHelper {
    private int score;

    public ScoreHelper(int score) {
        this.score = score;
    }

    public int getScore() {
        return score;
    }

    public void incrementScore() {
        this.score++;
    }

    public void resetScore() {
        this.score = 0;
    }

    public boolean isHighScore(int highScore) {
        return this.score > highScore;
    }
}
