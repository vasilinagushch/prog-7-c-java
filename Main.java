// main.java
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Locale;
import java.util.Random;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Locale.setDefault(new Locale("ru", "RU")); // Установить локаль на русскую
        new Random().setSeed(System.currentTimeMillis()); // Инициализация генератора случайных чисел

        Game game = new Game();

        Scanner scanner = new Scanner(System.in);
        System.out.print("Введите ваше имя (используя английские символы): ");
        String name = scanner.nextLine();
        game.setPlayerName(name);
        game.initializePuzzles();
        game.initializePhrases();
        game.startGame();

        game.addPlayer(new Player("Ivan", 10)); // Пример добавления игроков с очками
        game.addPlayer(new Player("Maria", 15));
        game.addPlayer(new Player("Alex", 5));

        System.out.println("Все игроки:");
        game.printAllPlayers();

        System.out.println("\nСортировка игроков по очкам:");
        game.sortPlayersByScore();
        game.printAllPlayers();

        System.out.println("\nПоиск игрока по имени:");
        Player foundPlayer = game.findPlayerByName("Maria");
        if (foundPlayer != null) {
            System.out.println("Игрок найден: " + foundPlayer.getName() + ", Очки: " + foundPlayer.getScore());
        } else {
            System.out.println("Игрок не найден");
        }
        scanner.close();
    }
}