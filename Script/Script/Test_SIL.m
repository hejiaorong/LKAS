%% SIL or PIL Simulation with a Top Model
% Test generated model code by running a top-model SIL or PIL simulation.
% With this approach:
%
% * You test code generated from the top model, which uses the standalone code interface.
% * You configure the model to load test vectors or stimulus inputs from the MATLAB workspace.
% * You can easily switch the top model between the normal, SIL, and PIL simulation modes.
%
% Open a simple counter top model.
model='LKAS_TestHarness';
close_system(model,0)
open_system(model)

%%
% To focus on numerical equivalence testing, turn off:
%
% * Model coverage
% * Code coverage
% * Execution time profiling
set_param(gcs, 'RecordCoverage','off');
coverageSettings = get_param(model, 'CodeCoverageSettings');
coverageSettings.CoverageTool='None';
set_param(model, 'CodeCoverageSettings',coverageSettings);
set_param(model, 'CodeExecutionProfiling','off');

%%
% Configure the input stimulus data.
% [ticks_to_count, reset, counter_mode, count_enable] = ...
%     rtwdemo_sil_topmodel_data(T);

%%
% Configure logging options in the model.
set_param(model, 'LoadExternalInput','on');
%set_param(model, 'ExternalInput','ticks_to_count, reset, counter_mode, count_enable');
set_param(model, 'SignalLogging', 'on');
set_param(model, 'SignalLoggingName', 'logsOut');

%%
% Run a normal mode simulation.
set_param(model,'SimulationMode','normal')
[~, ~, yout_normal] = sim(model,10);

%%
% Run a top-model SIL simulation.
set_param(model,'SimulationMode','Software-in-the-Loop')
[ ~,~,yout_sil] = sim(model,10);

%%
% Unless up-to-date code for this model exists, new code is generated and
% compiled. The generated code runs as a separate process on your computer.

%% 
% Plot and compare the results of the normal and SIL simulations. Observe
% that the results match.
% fig1 = figure;
% subplot(3,1,1), plot(yout_normal), title('Counter Output for Normal Simulation')
% subplot(3,1,2), plot(yout_sil), title('Counter Output for SIL Simulation')
% subplot(3,1,3), plot(yout_normal-yout_sil), ...
%     title('Difference Between Normal and SIL');
%%
% Clean up.
% close_system(model,0);
% if ishandle(fig1), close(fig1), end
% clear fig1
% simResults = {'yout_sil','yout_normal','model','T',...
%               'ticks_to_count','reset'};
% save([model '_results'],simResults{:});
% clear(simResults{:},'simResults')
