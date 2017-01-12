package com.example.park.management;

import android.content.Intent;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.toolbox.Volley;

import org.json.JSONException;
import org.json.JSONObject;

import static com.example.park.management.R.id.idcheckbutton;
import static com.example.park.management.R.id.idcheckbutton;
import static com.example.park.management.R.id.registerbutton;


public class RegisterActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_register);

        final EditText idText = (EditText) findViewById(R.id.idText);
        final EditText passwordText = (EditText) findViewById(R.id.passwordText);
        final EditText password2Text = (EditText) findViewById(R.id.password2Text);
        final EditText nameText = (EditText) findViewById(R.id.nameText);
        final EditText studentnumberText = (EditText) findViewById(R.id.studentnumberText);

        Button registerButton = (Button) findViewById(registerbutton);
        Button idcheckButton = (Button) findViewById(idcheckbutton);

        idcheckButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String userID = idText.getText().toString();

            }
        });

        registerButton.setOnClickListener(new View.OnClickListener() {

            public void onClick(View view) {
                final String userID = idText.getText().toString();
                final String userPassword = passwordText.getText().toString();
                final String userPassword2 = password2Text.getText().toString();
                final String userName = nameText.getText().toString();
                final int userStudentNumber = Integer.parseInt(studentnumberText.getText().toString());


                Response.Listener<String> responseListener = new Response.Listener<String>() {
                    public void onResponse(String response) {
                        try {
                            JSONObject jsonResponse = new JSONObject(response);
                            boolean success ;
                            if(userID == "" || userPassword == "" || userPassword2 == "" || userName == "" || userStudentNumber == 00) {
                                success = false;
                            }
                            else {
                                if(userPassword == userPassword2) {
                                    success = true;
                                }
                                else {
                                    success = false;
                                }
                            }
                            if(success) {
                                AlertDialog.Builder builder = new AlertDialog.Builder(RegisterActivity.this);
                                    builder.setMessage("회원가입되셨습니다.")
                                            .setPositiveButton("확인", null)
                                            .create()
                                            .show();
                                Intent intent = new Intent(RegisterActivity.this, LoginActivity.class);
                                RegisterActivity.this.startActivity(intent);
                            }
                            else{
                                AlertDialog.Builder builder = new AlertDialog.Builder(RegisterActivity.this);
                                if(userID == "" || userPassword == "" || userPassword2 == "" || userName == "" || userStudentNumber == 00) {
                                    builder.setMessage("회원정보를 모두 입력해주세요.")
                                            .setNegativeButton("다시시도", null)
                                            .create()
                                            .show();
                                }
                                else if(userPassword != userPassword2) {
                                    builder.setMessage("2차 비밀번호가 다릅니다.")
                                            .setNegativeButton("다시시도", null)
                                            .create()
                                            .show();
                                }
                            }
                        }
                        catch (JSONException e) {
                            e.printStackTrace();
                        }
                    }
                };
                RegisterRequest registerRequest = new RegisterRequest(userID, userPassword, userName, userStudentNumber, responseListener);
                RequestQueue queue = Volley.newRequestQueue(RegisterActivity.this);
                queue.add(registerRequest);
            }
        });
    }
}
