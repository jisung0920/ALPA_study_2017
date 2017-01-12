package com.example.park.management;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.Toast;

import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.toolbox.Volley;

import org.json.JSONException;
import org.json.JSONObject;

import static com.example.park.management.R.id.registerbutton;
import static com.example.park.management.R.id.validatebutton;


public class RegisterActivity extends AppCompatActivity {
    private ArrayAdapter adapter;
    private Spinner spinner;
    private String userID;
    private String userPassword;
    private  String userName;
    private  String StudentNumber;
    private AlertDialog dialog;
    private boolean validate = false;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_register);

        final EditText idText = (EditText) findViewById(R.id.idText);
        final EditText passwordText = (EditText) findViewById(R.id.passwordText);
        final EditText password2Text = (EditText) findViewById(R.id.password2Text);
        final EditText nameText = (EditText) findViewById(R.id.nameText);

        final Button registerButton = (Button) findViewById(registerbutton);
        final Button validateButton = (Button) findViewById(validatebutton);

        spinner = (Spinner) findViewById(R.id.studentnumberspinner);
        adapter = ArrayAdapter.createFromResource(this, R.array.studentnumber, android.R.layout.simple_spinner_dropdown_item);
        spinner.setAdapter(adapter);

        validateButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                String userID = idText.getText().toString();
                if(validate) {
                    return;
                }
                if(userID.equals("")) {
                    AlertDialog.Builder builder = new AlertDialog.Builder(RegisterActivity.this);
                    dialog = builder.setMessage("아이디를 입력해주세요")
                            .setPositiveButton("확인", null)
                            .create();
                    dialog.show();
                    return;
                }
                Response.Listener<String> responseListener = new Response.Listener<String>() {
                    @Override
                    public void onResponse(String response) {
                        try {
                            JSONObject jsonResponse = new JSONObject(response);
                            boolean success = jsonResponse.getBoolean("success");
                            if(success) {
                                AlertDialog.Builder builder = new AlertDialog.Builder(RegisterActivity.this);
                                dialog = builder.setMessage("사용할수 있는 아이디입니다.")
                                        .setPositiveButton("확인", null)
                                        .create();
                                dialog.show();
                                idText.setEnabled(false);
                                validate = true;
                                idText.setBackgroundColor(getResources().getColor(R.color.colorGray));
                                validateButton.setBackgroundColor(getResources().getColor(R.color.colorGray));
                            }
                            else {
                                AlertDialog.Builder builder = new AlertDialog.Builder(RegisterActivity.this);
                                dialog = builder.setMessage("사용할수 없는 아이디입니다.")
                                        .setNegativeButton("확인", null)
                                        .create();
                                dialog.show();
                            }
                        }
                        catch (Exception e) {
                            e.printStackTrace();
                        }
                    }
                };
                ValidateRequest validateRequest = new ValidateRequest(userID, responseListener);
                RequestQueue queue = Volley.newRequestQueue(RegisterActivity.this);
                queue.add(validateRequest);
            }
        });

        registerButton.setOnClickListener(new View.OnClickListener() {

            public void onClick(View view) {
                final String userID = idText.getText().toString();
                final String userPassword = passwordText.getText().toString();
                final String userPassword2 = password2Text.getText().toString();
                final String userName = nameText.getText().toString();
                final String userStudentNumber = spinner.getSelectedItem().toString();

                if(!validate) {
                    AlertDialog.Builder builder = new AlertDialog.Builder(RegisterActivity.this);
                    dialog = builder.setMessage("아이디 중복체크를 해주세요.")
                            .setPositiveButton("확인", null)
                            .create();
                    dialog.show();
                    return;
                }


                Response.Listener<String> responseListener = new Response.Listener<String>() {
                    public void onResponse(String response) {
                        try {
                            JSONObject jsonResponse = new JSONObject(response);
                            boolean success ;
                            if(userID == "" || userPassword == "" || userPassword2 == "" || userName == "" || userStudentNumber == "") {
                                success = false;
                            }
                            else {
                                if(userPassword.equals(userPassword2)) {
                                    success = true;
                                }
                                else {
                                    success = false;
                                }
                            }
                            if(success) {
                                Toast.makeText(RegisterActivity.this, "회원가입 되셨습니다.", Toast.LENGTH_SHORT).show();
//                                AlertDialog.Builder builder = new AlertDialog.Builder(RegisterActivity.this);
//                                    builder.setMessage("회원가입되셨습니다.")
//                                            .setPositiveButton("확인", null)
//                                            .create()
//                                            .show();
                                Intent intent = new Intent(RegisterActivity.this, LoginActivity.class);
                                RegisterActivity.this.startActivity(intent);
                            }
                            else{
                                AlertDialog.Builder builder = new AlertDialog.Builder(RegisterActivity.this);
                                if(userID == "" || userPassword == "" || userPassword2 == "" || userName == "" || userStudentNumber == "") {
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
