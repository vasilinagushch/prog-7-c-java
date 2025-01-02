public class Phrase {
    private String text;

    public Phrase() {
        this.text = "";
    }

    public Phrase(String text) {
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
