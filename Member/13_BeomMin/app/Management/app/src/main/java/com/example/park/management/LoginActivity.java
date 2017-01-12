package com.example.park.management;

import android.app.Activity;
import android.content.Intent;
import android.content.SharedPreferences;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.toolbox.Volley;

import org.json.JSONObject;

public class LoginActivity extends AppCompatActivity {
    SharedPreferences pref;
    SharedPreferences.Editor editor;
    Boolean loginChecked;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);


        final EditText idText = (EditText) findViewById(R.id.idText);
        final EditText passwordText = (EditText) findViewById(R.id.passwordText);

        final Button loginButton = (Button) findViewById(R.id.loginbutton);
        final Button registerButton = (Button) findViewById(R.id.registerbutton);

        final CheckBox AutoLoginCheck = (CheckBox) findViewById(R.id.AutoLoginCheck);
        /////////////////////////////
        pref = getSharedPreferences("pref",0);
        editor = pref.edit();

        if(pref.getBoolean("checkbox",false)) {
            idText.setText(pref.getString("userID", null));
            passwordText.setText(pref.getString("userPassword", null));
            loginChecked = true;
            AutoLoginCheck.setChecked(loginChecked);
        }
        else {
            String userID = idText.getText().toString();
            String userPassword = passwordText.getText().toString();
            loginChecked = false;
            AutoLoginCheck.setChecked(loginChecked);
            editor.putString("userID", userID);
            editor.putString("userPassword", userPassword);
            editor.putBoolean("AutoLoginCheck", loginChecked);

        }
            /////////////////////////////
            registerButton.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    Intent registerIntent = new Intent(LoginActivity.this, RegisterActivity.class);
                    LoginActivity.this.startActivity(registerIntent);
                }
            });

            loginButton.setOnClickListener(new View.OnClickListener() {

                public void onClick(View view) {
                    String userID = idText.getText().toString();
                    String userPassword = passwordText.getText().toString();
//                    loginChecked = false;
////                    AutoLoginCheck.setChecked(loginChecked);
//                    editor.putString("userID", userID);
//                    editor.putString("userPassword", userPassword);
//                    editor.putBoolean("AutoLoginCheck", loginChecked);

                    Response.Listener<String> responesListener = new Response.Listener<String>() {
                        @Override
                        public void onResponse(String response) {
                            try {
                                JSONObject jsonResponse = new JSONObject(response);
                                boolean success = jsonResponse.getBoolean("success");
                                if (success) {
                                    String userID = jsonResponse.getString("userID");
                                    String userPassword = jsonResponse.getString("userPassword");

                                    Intent intent = new Intent(LoginActivity.this, MainActivity.class);
                                    intent.putExtra("userID", userID);
                                    intent.putExtra("userPassword", userPassword);
                                    LoginActivity.this.startActivity(intent);
                                } else {
                                    AlertDialog.Builder builder = new AlertDialog.Builder(LoginActivity.this);
                                    builder.setMessage("로그인에 실패")
                                            .setNegativeButton("다시시시도", null)
                                            .create()
                                            .show();
                                }
                            } catch (Exception e) {
                                e.printStackTrace();
                            }
                        }
                    };

                    LoginRequest loginRequest = new LoginRequest(userID, userPassword, responesListener);
                    RequestQueue queue = Volley.newRequestQueue(LoginActivity.this);
                    queue.add(loginRequest);
                }
            });

        //////////////////////////////////////////
//        pref = getSharedPreferences("pref", Activity.MODE_PRIVATE);
//        editor = pref.edit();
//        editor.putString("id", String.valueOf(idText));
//        editor.putString("pw", String.valueOf(passwordText));
//        editor.commit();
//        ///////////////////////////////////////////
//        ////////////////////////////////////////////////////////////////////////////////
//        AutoLoginCheck.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
//            @Override
//            public void onCheckedChanged(CompoundButton compoundButton, boolean isChecked) {
//                if(isChecked) {
//                    loginChecked = true;
//                } else {
//                    // if unChecked, removeAll
//                    loginChecked = false;
//                    editor.clear();
//                    editor.commit();
//                }
//            }
//        });
//
//
//        if(loginChecked) {
//            // if autoLogin Checked, save values
//            editor.putString("id", String.valueOf(idText));
//            editor.putString("pw", String.valueOf(passwordText));
//            editor.putBoolean("autoLogin", true);
//            editor.commit();
//        }
//        // goto mainActivity
//
//     else {
//        Toast.makeText(LoginActivity.this, "Login Failed", Toast.LENGTH_LONG).show();
//        // goto LoginActivity
//    }



////////////////////////////////////////////////////////////////////////////


    }
}

