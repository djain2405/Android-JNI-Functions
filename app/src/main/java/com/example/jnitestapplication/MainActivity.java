package com.example.jnitestapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    ArrayList<String> vals = new ArrayList<>();
    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        vals.add("This");
        vals.add("is");
        vals.add("a");
        vals.add("test");

        // calls to native methods

        // Convert Ascii to char value
        System.out.println(charFromAscii(97));

        // Convert char to String
        System.out.println(stringFromChar('a'));

        // Add new string to the above defined 'vals' arrayList
        String[] newArray = addStringToStringArray(vals.toArray(new String[vals.size()]), "application");

        // Print the list through system.out.println
        for(int i = 0; i < newArray.length; i++) {
            System.out.println("Printing Value of the list  " + newArray[i]);
        }
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
    public native String anotherStringFromJNI(String val);
    public native char charFromAscii(int num);
    public native String stringFromChar(char val);
    public native String[] addStringToStringArray(String[] arr, String newVal);
    public native void printList(String[] arr);
}
