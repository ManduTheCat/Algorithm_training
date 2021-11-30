package class_practice;

public class Animal {
    String name; // 인스턴스변수

    public void setName(String name) {
        this.name = name;
    }

    public static void main(String[] args) {
        Animal cat = new Animal();
        cat.setName("Mandu");
        Animal second_cat = new Animal();
        second_cat.setName("jully");
        System.out.println(cat.name);
        System.out.println(second_cat.name);
    }

}
