#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {

    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;

        auto sensor = getValue<input_DEV>(ctx);

        float tempC = getValue<input_TempC>(ctx);
        float rh = getValue<input_RH>(ctx);
        auto raw = sensor->measureRaw(tempC, rh);

        emitValue<output_Raw>(ctx, raw);
        emitValue<output_Done>(ctx, 1);

    }
}
