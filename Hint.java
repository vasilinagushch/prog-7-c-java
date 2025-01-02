//hint.java
public class Hint {
    private String text;

    public Hint() {
        this.text = "";
    }

    public Hint(String text) {
        this.text = text;
    }

    public String getText() {
        return text;
    }

    public void setText(String text) {
        this.text = text;
    }

    public void addText(String additionalText) {
        this.text += " " + additionalText;
    }

    public void clearText() {
        this.text = "";
    }
}

