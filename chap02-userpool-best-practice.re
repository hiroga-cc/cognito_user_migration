= UserPoolの設定・開発のベストプラクティス

//abstract{
UserPoolのオススメ設定とか
//}


とりまコンソール、そのあとCFnにすること
ずっとコンソールでもまあいいかもしれない。
    ユーザー移行が対象外だから。
CIでの更新はおすすめしない。鬼畜仕様だから。

=={sec-ext} 設定のベストプラクティス

=== 全てのエイリアスを設定する
デフォルトでは、エンドユーザーがサインインするために使えるのはユーザー名だけです。
ユーザー名以外に、メールアドレス・電話番号・preferred_username（ユーザーが変更可能なユーザー名）をログインに利用可能する設定があり、エイリアスと呼ばれています。
この設定は、UserPoolを作成後は変更することができません。強い理由がない限り、全てのエイリアスを選択することをオススメします。※

※引き継いだUserPoolのエイリアスに電話番号が設定されていなかったばかりに、筆者はUserPoolからUserPoolへのユーザー移行を行いました。とても大変でした。読者の皆様は同じ間違いをしませんように。


=== ユーザーアカウントの有効期限を明示的に設定する
UserPoolにサインアップしたユーザーは、デフォルトではサインアップ後7日間初回ログインをしなかった場合、そのユーザーにログインできなくなります。
簡単に言うと、初期パスワードに有効期限が設定されているようなものです。

この有効期限が過ぎた場合、以下のいずれかのAPIを利用して初期パスワードを再送する必要があります。
運用で対応するのは面倒なので、サインアップ時にチェック処理を走らせるなどして自動化するのをオススメします。

AdminCreateUser API
・招待メッセージが再送される。
・一時パスワードが発行される。
（RESENDをONにする）

AdminSetUserPassword API
・招待メッセージは再送されない。
・PermanentパラメータをFalseに指定した場合に、一時パスワードとして発行される


=== ユーザーの自己サインアップの許可・不許可
サインアップ前に特定のチェックを行いたいケースがあると思います。
そうした場合、バックエンドでユーザーのサインアップを受け付けるAPIを用意した上で、そのAPIの裏側でUserPoolのAdminCreateUser APIにアクセスする方法が考えられます。

以下に具体的なケースを挙げます。
1. アカウントの有効期限が過ぎたユーザーに対して、初期パスワードの再送を自動化したい場合。

2. メールアドレスでサインアップする際に、case-insensitiveにしたい場合（デフォルトはcase-sensitive）

3. すでにFacebookログインでサービスを利用しているユーザーが、同じメールアドレスでサインアップを試みた際にアカウント作成を中止したい場合。



=={sec-ext} 開発のベストプラクティス
=== サインイン


※拙作です


=== パスワードリセット時の古いパスワードの無効化
adminPasswordResetのこととか


=== バックエンドではsubではなくuseridを使うこと

=== メールはSESで流すこと


=== クライアントIDをシェアしない


=== grant typeは最小限から


