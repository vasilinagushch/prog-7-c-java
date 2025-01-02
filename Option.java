// option.java
public class Option {
    private String text;

    public Option() {
        this.text = "";
    }

    public Option(String text) {
        this.text = text;
    }

    public String getText() {
        return text;
    }

    public void setText(String text) {
        this.text = text;
    }

    public void appendText(String additionalText) {
        this.text += " " + additionalText;
    }

    public void clearText() {
        this.text = "";
    }
}

